cmake_minimum_required(VERSION 3.14.2)

project(StripUnkAttr)

set(StripUnkAttr_SRC_FILES
    strip_unknown_attributes.cpp 
	strip_unknown_attributes_pass.cpp 
	)

add_library(StripUnkAttr STATIC ${StripUnkAttr_SRC_FILES})

target_link_libraries(StripUnkAttr)
