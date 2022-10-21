cmake_minimum_required(VERSION 3.15)

project(${CMAKE_PROJECT_NAME}Bin VERSION "${MAIN_PROJECT_VERSION}" LANGUAGES CXX)

# ======== setup project binaries ========

file(GLOB_RECURSE PROJECT_BUILD_BINARIES "*/*.cpp")

foreach (main_source ${PROJECT_BUILD_BINARIES})
    file(RELATIVE_PATH main_path ${PROJECT_BINARY_DIR} ${main_source})
    get_filename_component(binary_name ${main_path} NAME_WE)
    get_filename_component(binary_area_path_name ${main_path} DIRECTORY)
    get_filename_component(binary_area_name ${binary_area_path_name} NAME_WE)
    get_filename_component(package_name_path_name ${binary_area_path_name} DIRECTORY)
    get_filename_component(package_name ${package_name_path_name} NAME_WE)

    if (${package_name} STREQUAL "arena")
        set(package_name ${binary_area_name})
    endif ()
    set(scoped_binary_name "${package_name}_${binary_name}")    # eg games_sudoku_solver_cli
    message(STATUS "Adding ${scoped_binary_name} ==> [${package_name}] :: [${binary_area_name}] :: ${binary_name}")

    # ======== setup project binary target ========
    add_executable(${scoped_binary_name} ${main_source})
    set(link_libraries arena ${CONAN_LIBS})
    target_compile_features(${scoped_binary_name} PUBLIC cxx_std_20)
#    target_link_libraries(${scoped_binary_name} PUBLIC ${link_libraries} pthread dl)
    target_link_libraries(${scoped_binary_name} PUBLIC ${link_libraries})
    target_include_directories(${scoped_binary_name} PUBLIC ${MAIN_PROJECT_INCLUDE_DIRS})
    install(TARGETS ${scoped_binary_name})
endforeach ()
