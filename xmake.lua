add_rules("mode.debug", "mode.release")

add_requires("glfw")

includes("external/xmake_soloud.lua")

add_requires("soloud")

target("helloworld")
    set_kind("binary")
    set_languages("cxx17")

    add_deps("bbqengine")
    
    add_files("demo/helloworld.cpp")

    -- Copy assets
    after_build(function (target)
        cprint("Copying assets")
        os.cp("$(projectdir)/assets", path.directory(target:targetfile()))
    end)

target("bbqengine")
    set_kind("static")
    set_languages("cxx17")

    -- Declare our engine's header path.
    -- This allows targets that depend on the engine to #include them.
    add_includedirs("src", {public = true})
    
    -- Add all .cpp files in the `src` directory.
    add_files("src/*.cpp")

    --add packages
    add_packages("glfw", {public = true})
    add_packages("soloud", {public = true})