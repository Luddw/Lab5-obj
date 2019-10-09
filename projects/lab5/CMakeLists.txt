#--------------------------------------------------------------------------
# lab5 project
#--------------------------------------------------------------------------

PROJECT(lab5)
FILE(GLOB lab5_headers code/*.h)
FILE(GLOB lab5_sources code/*.cc)

SET(files_lab5 ${lab5_headers} ${lab5_sources})
SOURCE_GROUP("lab5" FILES ${files_lab5})

ADD_EXECUTABLE(lab5 ${files_lab5})
TARGET_LINK_LIBRARIES(lab5 core render GraphicNode)
ADD_DEPENDENCIES(lab5 core render GraphicNode)