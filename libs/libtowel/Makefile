# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 16:48:28 by nmuller           #+#    #+#              #
#    Updated: 2018/04/26 23:32:54 by pbeller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


##############
# PARAMETERS #
##############

# directories
SRC_PATH = srcs
OBJ_PATH = obj


# compiler flags
CC = clang
CFLAGS = -Werror -Wall -Wextra -Iinc
LFLAGS = -I includes

# linker flags
LKFLAGS = 

# files
SRC_FILES =	twl_argparser/argparser/argparser_add_argument.c\
			twl_argparser/argparser/argparser_del.c\
			twl_argparser/argparser/argparser_get_help_str.c\
			twl_argparser/argparser/argparser_new.c\
			twl_argparser/argparser/argparser_parse.c\
			twl_argparser/argparser/argparser_parse_build_argument__.c\
			twl_argparser/argparser/argparser_parse_build_result_item_inner__.c\
			twl_argparser/argparser/argparser_parse_from_arr.c\
			twl_argparser/argparser/argparser_print_help.c\
			twl_argparser/argparser/argparser_set_usage.c\
			twl_argparser/argparser_argument/argparser_argument_del.c\
			twl_argparser/argparser_argument/argparser_argument_del_void.c\
			twl_argparser/argparser_argument/argparser_argument_get_keys_ast_str.c\
			twl_argparser/argparser_argument/argparser_argument_new.c\
			twl_argparser/argparser_argument/argparser_argument_test_by_key.c\
			twl_argparser/argparser_argument/argparser_argument_test_by_key_void.c\
			twl_argparser/argparser_argument_mgr/argparser_argument_mgr_add.c\
			twl_argparser/argparser_argument_mgr/argparser_argument_mgr_del.c\
			twl_argparser/argparser_argument_mgr/argparser_argument_mgr_find_by_key.c\
			twl_argparser/argparser_argument_mgr/argparser_argument_mgr_get_all_chars.c\
			twl_argparser/argparser_argument_mgr/argparser_argument_mgr_new.c\
			twl_argparser/argparser_argument_mgr/argparser_argument_mgr_print.c\
			twl_argparser/argparser_result/argparser_result_add.c\
			twl_argparser/argparser_result/argparser_result_del.c\
			twl_argparser/argparser_result/argparser_result_find_item_by_key.c\
			twl_argparser/argparser_result/argparser_result_new.c\
			twl_argparser/argparser_result/argparser_result_opt_get_arg.c\
			twl_argparser/argparser_result/argparser_result_opt_is_set.c\
			twl_argparser/argparser_result/argparser_result_print.c\
			twl_argparser/argparser_result/argparser_result_print_error_with_help.c\
			twl_argparser/argparser_result_item/argparser_result_item_del.c\
			twl_argparser/argparser_result_item/argparser_result_item_del_void.c\
			twl_argparser/argparser_result_item/argparser_result_item_new.c\
			twl_arr/twl_arr_count.c\
			twl_arr/twl_arr_cpy.c\
			twl_arr/twl_arr_del.c\
			twl_arr/twl_arr_delone.c\
			twl_arr/twl_arr_filter.c\
			twl_arr/twl_arr_filter_del.c\
			twl_arr/twl_arr_find.c\
			twl_arr/twl_arr_indexof.c\
			twl_arr/twl_arr_iter.c\
			twl_arr/twl_arr_last.c\
			twl_arr/twl_arr_len.c\
			twl_arr/twl_arr_new.c\
			twl_arr/twl_arr_push.c\
			twl_arr/twl_arr_putstr.c\
			twl_arr/twl_arr_qsort.c\
			twl_arr/twl_arr_rev.c\
			twl_arr/twl_arr_sort.c\
			twl_arr/twl_arr_swap.c\
			twl_arr/twl_arr_to_lst.c\
			twl_arr2/twl_arr2_del.c\
			twl_arr2/twl_arr2_iter.c\
			twl_arr2/twl_arr2_iter_coord.c\
			twl_arr2/twl_arr2_new.c\
			twl_arr2/twl_arr2_rotate.c\
			twl_assert/twl_assert.c\
			twl_byte/twl_byterev.c\
			twl_ctype/twl_isalnum.c\
			twl_ctype/twl_isalpha.c\
			twl_ctype/twl_isascii.c\
			twl_ctype/twl_isblank.c\
			twl_ctype/twl_iscntrl.c\
			twl_ctype/twl_isdigit.c\
			twl_ctype/twl_isgraph.c\
			twl_ctype/twl_islower.c\
			twl_ctype/twl_isprint.c\
			twl_ctype/twl_ispunct.c\
			twl_ctype/twl_isspace.c\
			twl_ctype/twl_isupper.c\
			twl_ctype/twl_isxdigit.c\
			twl_ctype/twl_tolower.c\
			twl_ctype/twl_toupper.c\
			twl_debug/debug_main_end.c\
			twl_debug/debug_main_start.c\
			twl_dict/twl_dict_add.c\
			twl_dict/twl_dict_copy.c\
			twl_dict/twl_dict_del.c\
			twl_dict/twl_dict_del_by_key.c\
			twl_dict/twl_dict_get.c\
			twl_dict/twl_dict_get_elem__.c\
			twl_dict/twl_dict_iter.c\
			twl_dict/twl_dict_itern.c\
			twl_dict/twl_dict_key_exist.c\
			twl_dict/twl_dict_key_from_value.c\
			twl_dict/twl_dict_keys.c\
			twl_dict/twl_dict_len.c\
			twl_dict/twl_dict_new.c\
			twl_dict/twl_dict_set.c\
			twl_gnl/twl_gnl.c\
			twl_graph/twl_graph_add_edge.c\
			twl_graph/twl_graph_add_node.c\
			twl_graph/twl_graph_breadth_first_shortest_path.c\
			twl_graph/twl_graph_clear_node.c\
			twl_graph/twl_graph_clear_remove_node.c\
			twl_graph/twl_graph_copy.c\
			twl_graph/twl_graph_debug_print.c\
			twl_graph/twl_graph_del.c\
			twl_graph/twl_graph_edge_count.c\
			twl_graph/twl_graph_find_node.c\
			twl_graph/twl_graph_find_node_data.c\
			twl_graph/twl_graph_find_node_id.c\
			twl_graph/twl_graph_get_neighbors_data.c\
			twl_graph/twl_graph_get_node.c\
			twl_graph/twl_graph_get_node_data.c\
			twl_graph/twl_graph_iter_node.c\
			twl_graph/twl_graph_new.c\
			twl_graph/twl_graph_node_count.c\
			twl_graph/twl_graph_remove_node.c\
			twl_graph_edge/twl_graph_edge_del.c\
			twl_graph_edge/twl_graph_edge_equal.c\
			twl_graph_edge/twl_graph_edge_get_data.c\
			twl_graph_edge/twl_graph_edge_get_left_node.c\
			twl_graph_edge/twl_graph_edge_get_other_node.c\
			twl_graph_edge/twl_graph_edge_get_right_node.c\
			twl_graph_edge/twl_graph_edge_new.c\
			twl_graph_edge_mgr/twl_graph_edge_mgr_find_by_id.c\
			twl_graph_node/twl_graph_node_add_edge.c\
			twl_graph_node/twl_graph_node_del.c\
			twl_graph_node/twl_graph_node_get_data.c\
			twl_graph_node/twl_graph_node_get_edges.c\
			twl_graph_node/twl_graph_node_get_id.c\
			twl_graph_node/twl_graph_node_neighbors.c\
			twl_graph_node/twl_graph_node_neighbors_data.c\
			twl_graph_node/twl_graph_node_new.c\
			twl_graph_node/twl_graph_node_remove_edge.c\
			twl_graph_node_mgr/twl_graph_node_mgr_contains.c\
			twl_graph_node_mgr/twl_graph_node_mgr_find_by_id.c\
			twl_graphics/get_rgb_color.c\
			twl_graphics/get_rgba_color.c\
			twl_htab/twl_htab_del.c\
			twl_htab/twl_htab_get.c\
			twl_htab/twl_htab_get_bucket_.c\
			twl_htab/twl_htab_get_bucket_node_.c\
			twl_htab/twl_htab_get_hash_.c\
			twl_htab/twl_htab_get_or_create_bucket_.c\
			twl_htab/twl_htab_iter.c\
			twl_htab/twl_htab_len.c\
			twl_htab/twl_htab_new.c\
			twl_htab/twl_htab_set.c\
			twl_htab_node/twl_htab_node_del.c\
			twl_htab_node/twl_htab_node_new.c\
			twl_htab_node/twl_htab_node_set_data.c\
			twl_logger/twl_logger_printf.c\
			twl_lst/twl_lst_cat.c\
			twl_lst/twl_lst_clear.c\
			twl_lst/twl_lst_copy.c\
			twl_lst/twl_lst_copy_until.c\
			twl_lst/twl_lst_count.c\
			twl_lst/twl_lst_create_elem__.c\
			twl_lst/twl_lst_del.c\
			twl_lst/twl_lst_del_elem__.c\
			twl_lst/twl_lst_extend.c\
			twl_lst/twl_lst_extend_front.c\
			twl_lst/twl_lst_find.c\
			twl_lst/twl_lst_find2.c\
			twl_lst/twl_lst_find_and_pop.c\
			twl_lst/twl_lst_findall.c\
			twl_lst/twl_lst_first.c\
			twl_lst/twl_lst_get.c\
			twl_lst/twl_lst_get_elem__.c\
			twl_lst/twl_lst_get_rand.c\
			twl_lst/twl_lst_indexof.c\
			twl_lst/twl_lst_insert.c\
			twl_lst/twl_lst_insert_lst.c\
			twl_lst/twl_lst_iter.c\
			twl_lst/twl_lst_iter0.c\
			twl_lst/twl_lst_iter2.c\
			twl_lst/twl_lst_iter2n.c\
			twl_lst/twl_lst_iter_elem__.c\
			twl_lst/twl_lst_iterb.c\
			twl_lst/twl_lst_iteri.c\
			twl_lst/twl_lst_itern.c\
			twl_lst/twl_lst_iternp.c\
			twl_lst/twl_lst_iterp.c\
			twl_lst/twl_lst_last.c\
			twl_lst/twl_lst_len.c\
			twl_lst/twl_lst_link3__.c\
			twl_lst/twl_lst_link__.c\
			twl_lst/twl_lst_map.c\
			twl_lst/twl_lst_new.c\
			twl_lst/twl_lst_new_fill.c\
			twl_lst/twl_lst_pop_back.c\
			twl_lst/twl_lst_pop_front.c\
			twl_lst/twl_lst_popi.c\
			twl_lst/twl_lst_push_back.c\
			twl_lst/twl_lst_push_front.c\
			twl_lst/twl_lst_putstr.c\
			twl_lst/twl_lst_qsort.c\
			twl_lst/twl_lst_reduce.c\
			twl_lst/twl_lst_reducei.c\
			twl_lst/twl_lst_remove_if.c\
			twl_lst/twl_lst_remove_mult.c\
			twl_lst/twl_lst_rev.c\
			twl_lst/twl_lst_shift.c\
			twl_lst/twl_lst_shuffle.c\
			twl_lst/twl_lst_slice.c\
			twl_lst/twl_lst_sort.c\
			twl_lst/twl_lst_strjoin.c\
			twl_lst/twl_lst_swap.c\
			twl_lst/twl_lst_to_arr.c\
			twl_lst/twl_lst_to_arr2.c\
			twl_lst/twl_lst_unshift.c\
			twl_math/twl_abs.c\
			twl_math/twl_factorial.c\
			twl_math/twl_sqrt.c\
			twl_matrix/twl_matrix_new.c\
			twl_opt/twl_opt_args_get.c\
			twl_opt/twl_opt_args_len.c\
			twl_opt/twl_opt_check_invalid_opts.c\
			twl_opt/twl_opt_del.c\
			twl_opt/twl_opt_exist.c\
			twl_opt/twl_opt_get_param.c\
			twl_opt/twl_opt_new.c\
			twl_opt/twl_opt_new_parse_arg_opt_and_return_non_opt_args__.c\
			twl_opt_elem/twl_opt_elem_del.c\
			twl_opt_elem/twl_opt_elem_new.c\
			twl_point/twl_dcomplex_new.c\
			twl_point/twl_dpoint_init.c\
			twl_point/twl_point_del.c\
			twl_point/twl_point_init.c\
			twl_printf/srcs/pf_add_arg_to_elem.c\
			twl_printf/srcs/pf_build_pflist.c\
			twl_printf/srcs/pf_concat.c\
			twl_printf/srcs/pf_create.c\
			twl_printf/srcs/pf_free.c\
			twl_printf/srcs/pf_iter_pfelem.c\
			twl_printf/srcs/pf_prepare_xprintf__.c\
			twl_printf/srcs/pf_print_fd.c\
			twl_printf/srcs/pf_set_conv_str_fns/pf_set_conv_str_fns_char_string.c\
			twl_printf/srcs/pf_set_conv_str_fns/pf_set_conv_str_fns_f.c\
			twl_printf/srcs/pf_set_conv_str_fns/pf_set_conv_str_fns_hex.c\
			twl_printf/srcs/pf_set_conv_str_fns/pf_set_conv_str_fns_int.c\
			twl_printf/srcs/pf_set_conv_str_fns/pf_set_conv_str_fns_l.c\
			twl_printf/srcs/pf_set_conv_str_fns/pf_set_conv_str_fns_ll.c\
			twl_printf/srcs/pf_set_conv_str_fns/pf_set_conv_str_fns_wchar.c\
			twl_printf/srcs/pf_set_conv_str_fns.c\
			twl_printf/srcs/pf_set_conv_val_fns/pf_conv_val_char.c\
			twl_printf/srcs/pf_set_conv_val_fns/pf_conv_val_char_hh.c\
			twl_printf/srcs/pf_set_conv_val_fns/pf_conv_val_float.c\
			twl_printf/srcs/pf_set_conv_val_fns/pf_conv_val_int.c\
			twl_printf/srcs/pf_set_conv_val_fns/pf_conv_val_llong.c\
			twl_printf/srcs/pf_set_conv_val_fns/pf_conv_val_long.c\
			twl_printf/srcs/pf_set_conv_val_fns/pf_conv_val_percent.c\
			twl_printf/srcs/pf_set_conv_val_fns/pf_conv_val_short.c\
			twl_printf/srcs/pf_set_conv_val_fns/pf_conv_val_str.c\
			twl_printf/srcs/pf_set_conv_val_fns/pf_conv_val_uchar.c\
			twl_printf/srcs/pf_set_conv_val_fns/pf_conv_val_uint.c\
			twl_printf/srcs/pf_set_conv_val_fns/pf_conv_val_ullong.c\
			twl_printf/srcs/pf_set_conv_val_fns/pf_conv_val_ulong.c\
			twl_printf/srcs/pf_set_conv_val_fns/pf_conv_val_ushort.c\
			twl_printf/srcs/pf_set_conv_val_fns/pf_conv_val_wchar.c\
			twl_printf/srcs/pf_set_conv_val_fns/pf_conv_val_wstr.c\
			twl_printf/srcs/pf_set_conv_val_fns.c\
			twl_printf/srcs/pf_split.c\
			twl_printf/srcs/pfelem_convert_to_str.c\
			twl_printf/srcs/pfelem_create.c\
			twl_printf/srcs/pfelem_flag_add.c\
			twl_printf/srcs/pfelem_free.c\
			twl_printf/srcs/pfelem_has_valid_conv_spec.c\
			twl_printf/srcs/pfelem_is_raw_string.c\
			twl_printf/srcs/pfelem_min_width/pfelem_min_width_pad.c\
			twl_printf/srcs/pfelem_min_width_add.c\
			twl_printf/srcs/pfelem_post_str_conv.c\
			twl_printf/srcs/pfelem_pre_str_conv.c\
			twl_printf/srcs/pfelem_precision/pfelem_precision_handle_digits.c\
			twl_printf/srcs/pfelem_precision/pfelem_precision_handle_strings.c\
			twl_printf/srcs/pfelem_precision/pfelem_precision_set_wildcard.c\
			twl_printf/srcs/pfelem_precision_add.c\
			twl_printf/srcs/pfelem_split.c\
			twl_printf/srcs/pfelem_split_build.c\
			twl_printf/srcs/pfelem_split_process/pfelem_get_value_or_wildcard.c\
			twl_printf/srcs/pfelem_split_process/pfelem_set_conv_spec.c\
			twl_printf/srcs/pfelem_split_process/pfelem_set_flags.c\
			twl_printf/srcs/pfelem_split_process/pfelem_set_length_modifier.c\
			twl_printf/srcs/pfelem_split_process/pfelem_set_min_width.c\
			twl_printf/srcs/pfelem_split_process/pfelem_set_precision.c\
			twl_printf/srcs/pfelem_split_process.c\
			twl_printf/srcs/pfelem_str2pfelem.c\
			twl_printf/srcs/pfelem_utils.c\
			twl_printf/twl_asprintf.c\
			twl_printf/twl_dprintf.c\
			twl_printf/twl_prinft.c\
			twl_printf/twl_prinft_escape_nl.c\
			twl_printf/twl_sprintf.c\
			twl_range/twl_range_iter.c\
			twl_stdio/twl_putchar.c\
			twl_stdio/twl_strerror.c\
			twl_stdlib/twl_atof.c\
			twl_stdlib/twl_atoi.c\
			twl_string/twl_bzero.c\
			twl_string/twl_memccpy.c\
			twl_string/twl_memchr.c\
			twl_string/twl_memcmp.c\
			twl_string/twl_memcpy.c\
			twl_string/twl_memdup.c\
			twl_string/twl_memmove.c\
			twl_string/twl_memset.c\
			twl_string/twl_strcat.c\
			twl_string/twl_strchr.c\
			twl_string/twl_strcmp.c\
			twl_string/twl_strcpy.c\
			twl_string/twl_strdup.c\
			twl_string/twl_strdup_void.c\
			twl_string/twl_strlcat.c\
			twl_string/twl_strlen.c\
			twl_string/twl_strncat.c\
			twl_string/twl_strncmp.c\
			twl_string/twl_strncpy.c\
			twl_string/twl_strnstr.c\
			twl_string/twl_strrchr.c\
			twl_string/twl_strstr.c\
			twl_vector2/twl_vector2_bresenham.c\
			twl_vector2/twl_vector2_del.c\
			twl_vector2/twl_vector2_is_equal.c\
			twl_vector2/twl_vector2_new.c\
			twl_xstdio/twl_fd_to_str.c\
			twl_xstdio/twl_file_to_str.c\
			twl_xstdio/twl_lprintf.c\
			twl_xstdio/twl_putchar_fd.c\
			twl_xstdio/twl_putchar_tty.c\
			twl_xstdio/twl_putnbr.c\
			twl_xstdio/twl_putnbr_fd.c\
			twl_xstdio/twl_putnchar.c\
			twl_xstdio/twl_putnstr_fd.c\
			twl_xstdio/twl_putstr.c\
			twl_xstdio/twl_putstr_fd.c\
			twl_xstdio/twl_realloc.c\
			twl_xstdio/twl_xprintf.c\
			twl_xstdlib/twl_clockrand.c\
			twl_xstdlib/twl_joinpath.c\
			twl_xstdlib/twl_malloc_x0.c\
			twl_xstdlib/twl_rand.c\
			twl_xstdlib/twl_randint.c\
			twl_xstdlib/twl_xmalloc.c\
			twl_xstring/twl_add_char.c\
			twl_xstring/twl_itoa.c\
			twl_xstring/twl_ldtoa.c\
			twl_xstring/twl_lltoa.c\
			twl_xstring/twl_llutoa.c\
			twl_xstring/twl_llutobasestr.c\
			twl_xstring/twl_memswap.c\
			twl_xstring/twl_str_before_any_char.c\
			twl_xstring/twl_str_compress_char.c\
			twl_xstring/twl_str_contains_only.c\
			twl_xstring/twl_str_count_char.c\
			twl_xstring/twl_str_ends_with.c\
			twl_xstring/twl_str_is_int.c\
			twl_xstring/twl_str_is_num.c\
			twl_xstring/twl_str_is_pos_num.c\
			twl_xstring/twl_str_ncount_char.c\
			twl_xstring/twl_str_print_xtimes.c\
			twl_xstring/twl_str_replace.c\
			twl_xstring/twl_str_replace_char.c\
			twl_xstring/twl_str_replace_first.c\
			twl_xstring/twl_str_replace_free.c\
			twl_xstring/twl_str_split_get.c\
			twl_xstring/twl_str_split_once_to_lst.c\
			twl_xstring/twl_str_split_to_lst.c\
			twl_xstring/twl_str_starts_with.c\
			twl_xstring/twl_str_to_av.c\
			twl_xstring/twl_str_truncate.c\
			twl_xstring/twl_str_truncate_free.c\
			twl_xstring/twl_strcapitalize.c\
			twl_xstring/twl_strchr_any.c\
			twl_xstring/twl_strclr.c\
			twl_xstring/twl_strcountchar.c\
			twl_xstring/twl_strdel.c\
			twl_xstring/twl_strdup_or_null.c\
			twl_xstring/twl_strequ.c\
			twl_xstring/twl_strequ_void.c\
			twl_xstring/twl_striter.c\
			twl_xstring/twl_striteri.c\
			twl_xstring/twl_strjoin.c\
			twl_xstring/twl_strjoinarr.c\
			twl_xstring/twl_strjoinfree.c\
			twl_xstring/twl_strjoinlst.c\
			twl_xstring/twl_strlowcase.c\
			twl_xstring/twl_strmap.c\
			twl_xstring/twl_strmapi.c\
			twl_xstring/twl_strndup.c\
			twl_xstring/twl_strnequ.c\
			twl_xstring/twl_strnew.c\
			twl_xstring/twl_strnewc.c\
			twl_xstring/twl_strpad.c\
			twl_xstring/twl_strpos.c\
			twl_xstring/twl_strrev.c\
			twl_xstring/twl_strsplit.c\
			twl_xstring/twl_strsplit_mul.c\
			twl_xstring/twl_strsplit_mul_trim_chars.c\
			twl_xstring/twl_strstr_count.c\
			twl_xstring/twl_strstr_last.c\
			twl_xstring/twl_strsub.c\
			twl_xstring/twl_strswap.c\
			twl_xstring/twl_strtrim.c\
			twl_xstring/twl_strtrim_chars.c\
			twl_xstring/twl_strtrim_chars_free.c\
			twl_xstring/twl_strtrim_free.c\
			twl_xstring/twl_strupcase.c\
			twl_xstring/twl_wchar_to_str.c\
			twl_xstring/twl_wstr_to_str.c\
			twl_xstring/twl_wstrlen.c\
			twl_xsys/ioctl/term_cols.c\
			twl_xsys/ioctl/term_rows.c\
			twl_xsys/stat/twl_isblock.c\
			twl_xsys/stat/twl_isdir.c\
			twl_xsys/stat/twl_isdirl.c\
			twl_xsys/stat/twl_isexec.c\
			twl_xsys/stat/twl_isfifo.c\
			twl_xsys/stat/twl_islink.c\
			twl_xsys/stat/twl_issocket.c\
			twl_xsys/stat/twl_isspec_char.c\
			twl_xunistd/twl_exevep.c\
			twl_xunistd/twl_getch.c\
			twl_xunistd/twl_getcwd_str.c\
			twl_xunistd/twl_getopt.c



# executable name
NAME = libtowel.a

##############
# PROCESSING #
##############

# variables
OBJ_FILES = $(SRC_FILES:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_FILES))

# rules
.PHONY: clean fclean re norme lib fcleanall
all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	ar rc $@ $^
	ar -s $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(dir $@) 2> /dev/null || true
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

clean:
	@rm -fv $(OBJ)
	@rmdir -v $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
