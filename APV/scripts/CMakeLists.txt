
install(FILES ${CMAKE_SOURCE_DIR}/APV/scripts/config_gen.py
		DESTINATION bin
		)
install(FILES ${CMAKE_SOURCE_DIR}/APV/scripts/merge_single_run.py
		DESTINATION bin
		)
install(FILES ${CMAKE_SOURCE_DIR}/APV/scripts/config.yaml
		DESTINATION ${WORK_DIR}/config
		)