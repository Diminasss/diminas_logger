cmake_minimum_required(VERSION 3.10)
project(diminas_logger)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Флаг для выбора между STATIC и SHARED библиотекой
option(BUILD_SHARED_LIBS "Build shared (DLL) instead of static library" OFF)

# Создаём библиотеку logger (тип зависит от BUILD_SHARED_LIBS)
add_library(diminas_logger
        lib/src/diminas_logger.cpp
)
target_compile_definitions(diminas_logger
        PRIVATE DIMINAS_LOGGER_EXPORTS
)
# Указываем путь к заголовочным файлам только для logger
target_include_directories(diminas_logger
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/include
)


# Основной исполняемый файл
add_executable(main
        main.cpp
)



# Линкуем main с библиотекой logger
target_link_libraries(main diminas_logger)
