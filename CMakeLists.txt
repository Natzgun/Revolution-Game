cmake_minimum_required(VERSION 3.28)
project(Revolution_Game LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# Variables para fuentes cpp y cabeceras
set(MODEL_SOURCES
        Model/Model.cpp Model/Model.h
        Model/Entidad.cpp Model/Entidad.h
        Model/Jugador.cpp Model/Jugador.h
        Model/Juego.cpp Model/Juego.h
        Model/Personaje.cpp Model/Personaje.h
        Model/Item.cpp Model/Item.h
        Model/Firegun.cpp Model/Firegun.h
        Model/Proyectil.cpp Model/Proyectil.h
        Model/Stage.cpp Model/Stage.h)

set(VIEW_SOURCES
        View/View.cpp View/View.h
        View/Imagen.cpp View/Imagen.h
        View/Animation.cpp View/Animation.h
        View/JugadorView.cpp View/JugadorView.h
        View/Menu.cpp View/Menu.h
        View/JuegoView.cpp View/JuegoView.h
        View/ProyectilV.cpp View/ProyectilV.h View/MenuView.cpp View/MenuView.h View/Escenario.cpp View/Escenario.h View/States/GameState.h)

set(CONTROLLER_SOURCES
        Controller/Controller.cpp Controller/Controller.h
        Controller/Invoker.cpp Controller/Invoker.h
        Controller/Command.cpp Controller/Command.h)

# Agregar ejecutable
add_executable(Revolution_Game
        "main.cpp"
        ${MODEL_SOURCES}
        ${VIEW_SOURCES}
        ${CONTROLLER_SOURCES})

target_link_libraries(Revolution_Game PRIVATE SFML::Graphics SFML::Audio SFML::Network)
target_compile_features(Revolution_Game PRIVATE cxx_std_17)

# Copiar recursos al directorio de salida
add_custom_command(
    TARGET Revolution_Game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Resources
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Resources
    COMMENT "Copying Resources to output directory"
)

if(WIN32)
    add_custom_command(
        TARGET Revolution_Game
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:Revolution_Game>
        VERBATIM)
endif()