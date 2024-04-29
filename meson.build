project('testproj', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14'])

sdl2_dep = dependency('sdl2')
sdl2_main_dep = dependency('sdl2main')

executable(
           'testproj',
           'main.cpp',
           dependencies: [sdl2_dep, sdl2_main_dep],
           install : true
           )

              