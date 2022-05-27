
install(FILES ${CMAKE_SOURCE_DIR}/scripts/config_gen.py
		DESTINATION bin
		)
install(FILES ${CMAKE_SOURCE_DIR}/scripts/merge_single_run.py
		DESTINATION bin
		)
install(FILES ${CMAKE_SOURCE_DIR}/scripts/config.yaml
		DESTINATION ${WORK_DIR}/config
		)