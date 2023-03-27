cmake_minimum_required(VERSION 3.24)
set(PROJECT_NAME textboxProject)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp GUIComponent/GUIComponent.h Application.cpp Application.h Textbox/Font.cpp
        Textbox/Font.h Textbox/Letter.cpp Textbox/Letter.h Textbox/MultiText.cpp Textbox/MultiText.h Textbox/Typing.cpp
        Textbox/Typing.h Snapshot/SnapshotInterface.h States/States.cpp States/States.h EventHandler.h History/History.cpp History/History.h KeyShortcuts/KeyShortcuts.cpp KeyShortcuts/KeyShortcuts.h MouseEvents/MouseEvents.cpp MouseEvents/MouseEvents.h TextInput/TextInput.cpp TextInput/TextInput.h Components/TextBox.cpp Components/TextBox.h Components/Cursor.cpp Components/Cursor.h Snapshot/Snapshot.h AutoCorrect/Suggestion.cpp AutoCorrect/Suggestion.h AutoCorrect/FileReader.cpp AutoCorrect/FileReader.h AutoCorrect/Word.cpp AutoCorrect/Word.h Dropdown/Item.cpp Dropdown/Item.h Dropdown/ItemList.cpp Dropdown/ItemList.h Dropdown/DropdownMenu.cpp Dropdown/DropdownMenu.h Dropdown/InputBox.cpp Dropdown/InputBox.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()
