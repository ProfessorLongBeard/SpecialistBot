target_sources(${SP_TARGET} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/on_ready.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/on_sigint.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/on_application_create.c"
)