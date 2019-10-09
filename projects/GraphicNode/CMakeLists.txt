#--------------------------------------------------------------------------
# GraphicNode project
#--------------------------------------------------------------------------

PROJECT(GraphicNode)
FILE(GLOB GraphicNode_headers code/*.h)
FILE(GLOB GraphicNode_sources code/*.cc)

SET(files_GraphicNode ${GraphicNode_headers} ${GraphicNode_sources})
SOURCE_GROUP("GraphicNode" FILES ${files_GraphicNode})

ADD_LIBRARY(GraphicNode STATIC ${files_GraphicNode})
TARGET_LINK_LIBRARIES(GraphicNode core render MeshResource ShaderResource Texture Transform Cam)
ADD_DEPENDENCIES(GraphicNode core render MeshResource ShaderResource Texture Transform Cam)

TARGET_INCLUDE_DIRECTORIES(GraphicNode INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/code/)