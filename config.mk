CONFIG_NAME = rt
CONFIG_OUTPUT_TYPE = exec
CONFIG_RUN_CMD = ./$(CONFIG_NAME)
CONFIG_CC_FLAGS_EXTRA = -I minilibx
CONFIG_CC_FLAGS_EXTRA_POST = -L ./minilibx -l mlx -lXext -lX11 -lm -lpthread -fsanitize=address
