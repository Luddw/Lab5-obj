#--------------------------------------------------------------------------
# Transform project
#--------------------------------------------------------------------------

PROJECT(Transform)
FILE(GLOB Transform_headers code/*.h)
FILE(GLOB Transform_sources code/*.cc)

SET(files_Transform ${Transform_headers} ${Transform_sources})
SOURCE_GROUP("Transform" FILES ${files_Transform})

ADD_LIBRARY(Transform STATIC ${files_Transform})
TARGET_LINK_LIBRARIES(Transform core render Matlibrary)
ADD_DEPENDENCIES(Transform core render Matlibrary)

TARGET_INCLUDE_DIRECTORIES(Transform INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/code/)