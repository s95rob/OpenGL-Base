function(add_example EXAMPLE_NAME)
	add_executable(${EXAMPLE_NAME} GL-Examples/src/${EXAMPLE_NAME}.cpp)
	add_dependencies(${EXAMPLE_NAME} GL-Base)
	target_include_directories(${EXAMPLE_NAME} PUBLIC GL-Base/src)
	target_link_libraries(${EXAMPLE_NAME} GL-Base glfw3)

	# Visual Studio properties
	set_property(TARGET ${EXAMPLE_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/res")
	set_property(TARGET ${EXAMPLE_NAME} PROPERTY FOLDER "GL-Examples")
endfunction()