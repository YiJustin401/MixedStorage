function(MIXED_EXECUTE_BINARY target sources link_libraries)
    add_executable(${target} ${sources})
    if (link_libraries)
        target_link_libraries(${target} PUBLIC ${link_libraries})
    endif()
    target_link_libraries(${target} PUBLIC mixed_storage_lib)
endfunction()