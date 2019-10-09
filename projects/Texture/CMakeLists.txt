#--------------------------------------------------------------------------
# Texture project
#--------------------------------------------------------------------------

PROJECT(Texture)
FILE(GLOB Texture_headers code/*.h)
FILE(GLOB Texture_sources code/*.cc)

SET(files_Texture ${Texture_headers} ${Texture_sources})
SOURCE_GROUP("Texture" FILES ${files_Texture})

ADD_LIBRARY(Texture STATIC ${files_Texture})
TARGET_LINK_LIBRARIES(Texture core render)
ADD_DEPENDENCIES(Texture core render)

TARGET_INCLUDE_DIRECTORIES(Texture INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/code/)

add_custom_command(
    TARGET Texture POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/resources/
    ${CMAKE_SOURCE_DIR}/bin/resources/
)

set_target_properties(Texture PROPERTIES 
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/)