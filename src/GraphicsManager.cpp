#include "GraphicsManager.h"
#include "Types.h"
#include "Engine.h"
#include "EntityManager.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#define SOKOL_IMPL
#define SOKOL_GLCORE33
#include "sokol_gfx.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <string>
#include <iostream>
#include <unordered_map>


using namespace glm;



namespace {
struct Uniforms {
    mat4 projection;
    mat4 transform;
};
}

// namespace {
// struct GraphicsVars {
//     sg_pipeline pipeline;
//     sg_bindings bindings;
//     sg_pass_action pass_action;
// };
// }

using namespace bbq;
extern std::vector<Sprite> sprites;
extern Engine game;

class GraphicsManager::GraphicsManagerImpl
{
    friend class InputManager;
    private:


    public:
        GLFWwindow* window;
        sg_pipeline pipeline;
        sg_bindings bindings;
        sg_pass_action pass_action;
        //std::vector< Sprite > sprites;
        sg_image sample_image;
        std::unordered_map<string, sg_image> sokol_image_map;

};

GraphicsManager::GraphicsManager()
{
    mGraphicsManager = std::make_unique<GraphicsManagerImpl>();
}

GraphicsManager::~GraphicsManager()
{
    //idk?
}

void* GraphicsManager::GetWindow()
{
    return (void*) mGraphicsManager->window;
}

void GraphicsManager::Startup()
{
    
    //---GLFW SETUP---
    //hard coding these for now
    int window_width = 640;
    int window_height = 480;
    int window_fullscreen = 0;
    const char * window_name = "default window name";

    glfwInit();
    // We'll use sokol_gfx's OpenGL backend
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    //GLFWwindow* window = glfwCreateWindow( window_width, window_height, window_name, window_fullscreen ? glfwGetPrimaryMonitor() : 0, 0 );
    //this->window = (void*) glfwCreateWindow( window_width, window_height, window_name, window_fullscreen ? glfwGetPrimaryMonitor() : 0, 0 );
    mGraphicsManager->window = glfwCreateWindow( window_width, window_height, window_name, window_fullscreen ? glfwGetPrimaryMonitor() : 0, 0 );
    glfwSetWindowAspectRatio( (GLFWwindow*) mGraphicsManager->window, window_width, window_height );
    if( !mGraphicsManager->window ) //edited
    {
        std::cerr << "Failed to create a window." << std::endl;
        glfwTerminate();
    }
    //glfwMakeContextCurrent( (GLFWwindow*) this->window );
    glfwMakeContextCurrent( mGraphicsManager->window );
    glfwSwapInterval(0);
    //--- GLFW SETUP END---

    //---SOKOL SETUP ---
    //step1
    sg_setup(sg_desc{});

    //step2?
    // A vertex buffer containing a textured square.
    const struct {
        // position
        float x, y;
        // texcoords
        float u, v;
    } vertices[] = {
        // position       // texcoords
        { -1.0f,  -1.0f,    0.0f,  1.0f },
        {  1.0f,  -1.0f,    1.0f,  1.0f },
        { -1.0f,   1.0f,    0.0f,  0.0f },
        {  1.0f,   1.0f,    1.0f,  0.0f },
    };

    //step3: create sokol buffer description, fill .data with
    //sg_range struct containing verticies and sizeof(verticies)
    sg_buffer_desc buffer_desc{};
    buffer_desc.data = SG_RANGE(vertices);

    //step4 upload data to the GPU
    sg_buffer vertex_buffer = sg_make_buffer(buffer_desc);

    //step5 create pipeline desc struct, zero inited (defaul init in sokol)
    sg_pipeline_desc pipeline_desc{};

    //step 6: tell pipeline what our vertex data represents
    pipeline_desc.primitive_type = SG_PRIMITIVETYPE_TRIANGLE_STRIP;

    //Step 7: change some default settings
    //enable alpha blending
    pipeline_desc.colors[0].blend.enabled = true;
    pipeline_desc.colors[0].blend.src_factor_rgb = SG_BLENDFACTOR_SRC_ALPHA;
    pipeline_desc.colors[0].blend.dst_factor_rgb = SG_BLENDFACTOR_ONE_MINUS_SRC_ALPHA;

    // enable z buffer, delegates drawing order to gpu hardware 
    pipeline_desc.depth.compare = SG_COMPAREFUNC_LESS_EQUAL;
    pipeline_desc.depth.write_enabled = true;

    //step 8: tell pipline about vertex data layout
    pipeline_desc.layout.attrs[0].format = SG_VERTEXFORMAT_FLOAT2;
    pipeline_desc.layout.attrs[1].format = SG_VERTEXFORMAT_FLOAT2;

    //step 9: define our shader
    sg_shader_desc shader_desc{};

    //step 10: simple vertex shader
    shader_desc.vs.source = R"(
        #version 330
        uniform mat4 projection;
        uniform mat4 transform;
        layout(location=0) in vec2 position;
        layout(location=1) in vec2 texcoords0;
        out vec2 texcoords;
        void main() {
            gl_Position = projection*transform*vec4( position, 0.0, 1.0 );
            texcoords = texcoords0;
        })";

    //step11: Tell shader about the uniforms
    shader_desc.vs.uniform_blocks[0].size = sizeof(Uniforms);
    // The order of `.uniforms[0]` and `.uniforms[1]` must match the order in `Uniforms`
    shader_desc.vs.uniform_blocks[0].uniforms[0].name = "projection";
    shader_desc.vs.uniform_blocks[0].uniforms[0].type = SG_UNIFORMTYPE_MAT4;
    shader_desc.vs.uniform_blocks[0].uniforms[1].name = "transform";
    shader_desc.vs.uniform_blocks[0].uniforms[1].type = SG_UNIFORMTYPE_MAT4;

    //step 12: simple fragment shader
    shader_desc.fs.source = R"(
        #version 330
        uniform sampler2D tex;
        in vec2 texcoords;
        out vec4 frag_color;
        void main() {
            frag_color = texture( tex, texcoords );
            // If we're not drawing back to front, discard very transparent pixels so we
            // don't write to the depth buffer and prevent farther sprites from drawing.
            if( frag_color.a < 0.1 ) discard;
        }
    )";
    shader_desc.fs.images[0].name = "tex"; // The name should match the shader source code.
    shader_desc.fs.images[0].image_type = SG_IMAGETYPE_2D;

    //give frag shader same uniforms as vertex shader
    shader_desc.fs.uniform_blocks[0] = shader_desc.vs.uniform_blocks[0];

    //Step 13: make shader program, add to pipeline, then make entire pipeline
    pipeline_desc.shader = sg_make_shader( shader_desc );
    //sg_pipeline pipeline = sg_make_pipeline( pipeline_desc );
    mGraphicsManager->pipeline = sg_make_pipeline( pipeline_desc );
    //mGraphicsManager->pipeline = pipeline; //update instance var

    //Step 14: Create sg_pass_action struct, choose clear color.
    //tells sokol_gfx what to do with whatevers in the frame buffer already
    //when start drawing a frame.
    sg_pass_action pass_action{};
    mGraphicsManager->pass_action = pass_action;
    mGraphicsManager->pass_action.colors[0].action = SG_ACTION_CLEAR;
    mGraphicsManager->pass_action.colors[0].value = { /* red, green, blue, alpha floating point values for a color to fill the frame buffer with */ };
    //mGraphicsManager->pass_action = pass_action; //update instance var

    //step 15: "bind" our vertex_buffer data to our pipeline
    //for each draw call in an sg_bindings struct:
    sg_bindings bindings{};
    mGraphicsManager->bindings = bindings; //update instance vars
    mGraphicsManager->bindings.vertex_buffers[0] = vertex_buffer;
    

}

void GraphicsManager::Shutdown()
{
    //does nothing right now

    //SOKOL SHUTDOWN
    sg_shutdown();
}

bool GraphicsManager::ShouldQuit()
{
    //if (glfwWindowShouldClose((GLFWwindow*)this->window))
    if (glfwWindowShouldClose(mGraphicsManager->window))
    {
        return true;
    }
    return false;
}

bool GraphicsManager::LoadAnImage(const std::string& name, const std::string& path)
{
    string fullpath = path + name;
    
    //load image using stb
    int width, height, channels;
    //unsigned char* data = stbi_load( path.c_str(), &width, &height, &channels, 4 );
    unsigned char* data = stbi_load( fullpath.c_str(), &width, &height, &channels, 4 );

    //create sokol_gfx image description:
    sg_image_desc image_desc{};
    image_desc.width = width;
    image_desc.height = height;
    image_desc.pixel_format = SG_PIXELFORMAT_RGBA8;
    image_desc.min_filter = SG_FILTER_LINEAR;
    image_desc.mag_filter = SG_FILTER_LINEAR;
    image_desc.wrap_u = SG_WRAP_CLAMP_TO_EDGE;
    image_desc.wrap_v = SG_WRAP_CLAMP_TO_EDGE;
    image_desc.data.subimage[0][0].ptr = data;
    image_desc.data.subimage[0][0].size = (size_t)(width * height * 4);

    //upload image to GPU
    sg_image image = sg_make_image( image_desc );

    //added
    mGraphicsManager->sample_image = image;
    mGraphicsManager->sokol_image_map[name] = image;

    //Free date returned by stbi_load() since we are done with it
    stbi_image_free( data );

    //add sprite informatino to sprite vector
    Sprite s;
    s.image = name;
    s.scale = 100.0;
    s.position = glm::vec2(0.f, 0.f);
    s.z = 1.0;
    //mGraphicsManager->sprites.insert(mGraphicsManager->sprites.begin(),s);
    //mGraphicsManager->sprites.push_back(s);

    //sprites.push_back(s);
    game.resources.AddSprite(s);
    
    return false; //default
}

//void GraphicsManager::Draw(const std::vector< Sprite >& sprites)
void GraphicsManager::Draw()
{
    //Step 1: Get current frame buffer size
    int width, height;
    //glfwGetFramebufferSize((GLFWwindow*) this->window, &width, &height);
    glfwGetFramebufferSize(mGraphicsManager->window, &width, &height);

    //Step 2: Clear default frame buffer
    sg_begin_default_pass( mGraphicsManager->pass_action, width, height );

    //Step 3: Apply the pipeline
    sg_apply_pipeline( mGraphicsManager->pipeline );

    //Step 4: Make Uniforms struct, compute uniforms.projection from width and height
    Uniforms uniforms;

    // Start with an identity matrix.
    uniforms.projection = mat4{1};
    // Scale x and y by 1/100.
    uniforms.projection[0][0] = uniforms.projection[1][1] = 1./100.;
    // Scale the long edge by an additional 1/(long/short) = short/long.
    if( width < height ) {
        uniforms.projection[1][1] *= width;
        uniforms.projection[1][1] /= height;
    } else {
        uniforms.projection[0][0] *= height;
        uniforms.projection[0][0] /= width;
    }

    //allows currently for scaling and translating sprites assuming anchored by center.
    //uniforms.transform = translate( mat4{1}, vec3( position, z ) ) * scale( mat4{1}, vec3( scale ) );

    //Step 5: Draw Each Sprite
    //std::unordered_map ss = game.ecs.GetAppropriateSparseSet<Sprite>();
    //for( const auto& [entity, s] : ss )
    //for (Sprite s : sprites)
    game.ecs.ForEach<Sprite>( [&]( EntityID e )
    {
        Sprite& s = game.ecs.Get<Sprite>(e);
        //step i:
        Position global_position;
        global_position.x = game.ecs.Get<Position>(e).x + s.position.x;
        global_position.y = game.ecs.Get<Position>(e).y + s.position.y;
        //uniforms.transform = translate( mat4{1}, vec3( s.position, s.z ) ) * scale( mat4{1}, vec3( s.scale ) );
        uniforms.transform = translate( mat4{1}, vec3( global_position.x, global_position.y, s.z ) ) * scale( mat4{1}, vec3( s.scale ) );
        //scale quad down to fit inside square always
        // if( image_width < image_height ) {
        //     uniforms.transform = uniforms.transform * scale( mat4{1}, vec3( real(image_width)/image_height, 1.0, 1.0 ) );
        // } else {
        //     uniforms.transform = uniforms.transform * scale( mat4{1}, vec3( 1.0, real(image_height)/image_width, 1.0 ) );
        // }

        sg_apply_uniforms( SG_SHADERSTAGE_VS, 0, SG_RANGE(uniforms) );
        sg_apply_uniforms( SG_SHADERSTAGE_FS, 0, SG_RANGE(uniforms) );

        //step ii:
        //mGraphicsManager->bindings.fs_images[0] = mGraphicsManager->sample_image;
        mGraphicsManager->bindings.fs_images[0] = mGraphicsManager->sokol_image_map[s.image];
        sg_apply_bindings(mGraphicsManager->bindings);

        //step iii:
        sg_draw(0, 4, 1);
    } );


    //Step 6: finish drawing
    sg_end_pass();
    sg_commit();
    glfwSwapBuffers(mGraphicsManager->window);
}