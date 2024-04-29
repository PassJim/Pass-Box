project('sdldemo', 'c',
        default_options: 'default_library=static')

sdl2_dep = dependency('sdl2')
sdl2_main_dep = dependency('sdl2main')

executable('sdlprog', 'sdlprog.c',
           win_subsystem: 'windows',
           dependencies: [sdl2_dep, sdl2_main_dep])
