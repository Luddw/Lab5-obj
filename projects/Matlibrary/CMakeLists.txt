#--------------------------------------------------------------------------
# Matlibrary project
#--------------------------------------------------------------------------

PROJECT(Matlibrary)
FILE(GLOB Matlibrary_headers code/*.h)
FILE(GLOB Matlibrary_sources code/*.cc)

SET(files_Matlibrary ${Matlibrary_headers} ${Matlibrary_sources})
SOURCE_GROUP("Matlibrary" FILES ${files_Matlibrary})

ADD_LIBRARY(Matlibrary STATIC ${files_Matlibrary})
TARGET_LINK_LIBRARIES(Matlibrary core render)
ADD_DEPENDENCIES(Matlibrary core render)

TARGET_INCLUDE_DIRECTORIES(Matlibrary INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/code/)