file(GLOB files "*.cpp")
foreach(file ${files})
	get_filename_component(filename ${file} NAME_WE)
	message(STATUS "filename=${filename}")

	add_executable(${filename}
		${file})

	target_link_libraries(${filename}
		UnitTest++
		nfv2)

	add_test(${filename} ${filename})
endforeach()