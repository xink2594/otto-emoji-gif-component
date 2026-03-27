# Otto robot GIF emoji component
#
# This component provides embedded GIF emoji resources for LVGL.

# All source files including GIF arrays and utilities
set(COMPONENT_SRCS
    "src/otto_emoji_gif.c"
    "src/otto_emoji_gif_utils.c"
    "src/staticstate.c"
    "src/sad.c"
    "src/happy.c"
    "src/scare.c"
    "src/buxue.c"
    "src/anger.c"
)

# Register component
idf_component_register(
    SRCS ${COMPONENT_SRCS}
    INCLUDE_DIRS "include"
    REQUIRES "lvgl"
)

target_compile_definitions(${COMPONENT_LIB}
    PRIVATE OTTO_EMOJI_GIF_VERSION="1.1.0"
)

message(STATUS "Otto Emoji GIF Component: 6 embedded GIF resources loaded")
