target_include_directories(${CMAKE_PROJECT_NAME}
                            PRIVATE include 
                           ${CMAKE_CURRENT_SOURCE_DIR}
                           ${spdlog_SOURCE_DIR}/include
                           )

target_sources(${CMAKE_PROJECT_NAME}

    PRIVATE
    # INTERFACE
    INTERFACE_Draw.cpp

    # GAME ENVIRONMENT
    GameEnvironment.cpp

    # ANIMATION
    ANIMATION.cpp

    # GRAPHICS
    GRAPHICS_Sprites_Draw.cpp
    GRAPHICS_Sprites_Move.cpp
    GRAPHICS_Tiles_Animations.cpp
    GRAPHICS_Tiles_Define.cpp
    GRAPHICS_Tiles_Draw.cpp
    GRAPHICS_Tiles_Elements.cpp
    GRAPHICS_Tiles_Switch_Tile.cpp
    GRAPHICS_Sprites.cpp
    GRAPHICS_Sprites_Bullets.cpp

    # LOOP
    LOOP_Editor_Stages_Creator_Functions.cpp
    LOOP_Stagefile_Load.cpp
    LOOP_Editor_Stages_Enemies.cpp
    LOOP_Story.cpp
    LOOP_Editor_Stages_Interface.cpp
    LOOP_Editor_Stages_Set_Elements.cpp
    LOOP_Editor_Stages_Sprites.cpp
    LOOP_Editor_Stages_Stage_Settings.cpp
    LOOP_Editor_Tiles.cpp
    LOOP_Gameloop.cpp
    LOOP_Credits.cpp
    LOOP_Gameloop_Splashscreens.cpp
    LOOP_Editor_Stages.cpp
    LOOP_Menu.cpp
    LOOP_Editor_Stages_Creator.cpp
    LOOP_Options.cpp

    # STAGE
    STAGE_Draw.cpp
    STAGE_Interface_Draw.cpp

    # AUDIO
    Audio.cpp

    # ENEMIES 
    ENEMIES.cpp
    ENEMIES_Collision.cpp
    ENEMIES_Draw.cpp
    ENEMIES_Move.cpp

    # PLAYER
    PLAYER.cpp
    PLAYER_Collision_NonSolids.cpp
    PLAYER_Collision_Solids.cpp
    PLAYER_Collision_Solids_Specials.cpp
    PLAYER_Collision_Sprites.cpp
    PLAYER_Draw.cpp
    PLAYER_Jump.cpp
    PLAYER_Killed.cpp
    PLAYER_Run.cpp

    # CONTENT
    ContentManager.cpp
    CONTENT_Gametype_Load.cpp
    CONTENT_Stages_Load_Write.cpp

    # SYSTEM 
    SYSTEM_Debug_Infos.cpp
    SYSTEM_Draw_Text.cpp
    SYSTEM_Input_General.cpp
    SYSTEM_SDL_Textures.cpp
    SYSTEM_SDL_init.cpp   
    SYSTEM_SDL_input.cpp
    SYSTEM_Update_Screen.cpp
    SYSTEM_Vector_Operations.cpp


    main.cpp
)
#add_subdirectory(audio)

target_link_libraries(${PROJECT_NAME} 
                      ${SDL2_LIBRARY} 
                      ${SDL2_IMAGE_LIBRARIES}
                      ${SDL2_MIXER_LIBRARIES}
                      spdlog::spdlog 
)