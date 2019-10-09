#--------------------------------------------------------------------------
# ShaderResource project
#--------------------------------------------------------------------------

PROJECT(ShaderResource)
FILE(GLOB ShaderResource_headers code/*.h)
FILE(GLOB ShaderResource_sources code/*.cc)

SET(files_ShaderResource ${ShaderResource_headers} ${ShaderResource_sources})
SOURCE_GROUP("ShaderResource" FILES ${files_ShaderResource})

ADD_LIBRARY(ShaderResource STATIC ${files_ShaderResource})
TARGET_LINK_LIBRARIES(ShaderResource core render Matlibrary)
ADD_DEPENDENCIES(ShaderResource core render Matlibrary)

TARGET_INCLUDE_DIRECTORIES(ShaderResource INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/code/)

add_custom_command(
    TARGET ShaderResource POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/resources/
    ${CMAKE_SOURCE_DIR}/bin/resources/
)

set_target_properties(ShaderResource PROPERTIES 
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/)