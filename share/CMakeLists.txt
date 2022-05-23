configure_file("thisisomer.sh.in" thisisomer.sh @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/thisisomer.sh DESTINATION share/)