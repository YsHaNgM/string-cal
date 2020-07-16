set(_command_line_apps
  input
  iotest
)

foreach(_app ${_command_line_apps})
  add_executable(${_app} ${_app}.cpp)
  target_link_libraries(${_app} ${PHAS0100ASSIGNMENT1_LIBRARIES} ${ALL_THIRD_PARTY_LIBRARIES})
endforeach()