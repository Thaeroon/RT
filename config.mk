CONFIG_NAME = rt
CONFIG_OUTPUT_TYPE = exec
CONFIG_RUN_CMD = ./$(CONFIG_NAME)
CONFIG_CC_FLAGS_EXTRA = -I minilibx_macos
CONFIG_CC_FLAGS_EXTRA_POST = -framework OpenGL -framework AppKit minilibx_macos/libmlx.a -lpthread -fsanitize=address
