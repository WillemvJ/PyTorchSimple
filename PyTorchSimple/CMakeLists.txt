# CMakeList.txt : CMake project for PyTorchSimple, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (PyTorchSimple "PyTorchSimple.cpp" "PyTorchSimple.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PyTorchSimple PROPERTY CXX_STANDARD 20)
endif()


 find_package(Torch REQUIRED)

  target_link_libraries(PyTorchSimple PRIVATE "${TORCH_LIBRARIES}")
 if (MSVC)
  file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
  add_custom_command(TARGET PyTorchSimple
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:PyTorchSimple>)
endif (MSVC)

# TODO: Add tests and install targets if needed.
