//
// Copyright (c) 2017 The Khronos Group Inc.
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#include "../../test_common/harness/errorHelpers.h"
#include "../../test_common/harness/kernelHelpers.h"
#include "../../test_common/harness/typeWrappers.h"
#include "../../test_common/harness/conversions.h"
#include "../../test_common/harness/mt19937.h"

extern int        test_load_program_source(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int        test_load_multistring_source(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int        test_load_two_kernel_source(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int        test_load_null_terminated_source(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int        test_load_null_terminated_multi_line_source(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int        test_load_null_terminated_partial_multi_line_source(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int        test_load_discreet_length_source(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int        test_get_program_source(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int        test_get_program_build_info(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int        test_get_program_info(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);

extern int        test_large_compile(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int        test_async_build_pieces(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);

extern int      test_options_optimizations(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int        test_options_build_macro(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int        test_options_build_macro_existence(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int        test_options_include_directory(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int        test_options_denorm_cache(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);

extern int        test_preprocessor_define_udef(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int        test_preprocessor_include(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int        test_preprocessor_line_error(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int        test_preprocessor_pragma(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);

extern int      test_compiler_defines_for_extensions(cl_device_id device, cl_context context, cl_command_queue queue, int n_elems );
extern int test_image_macro(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);

extern int      test_simple_compile_only(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_simple_static_compile_only(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_simple_extern_compile_only(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_simple_compile_with_callback(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_simple_embedded_header_compile(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);

extern int      test_simple_link_only(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_two_file_regular_variable_access(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_two_file_regular_struct_access(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_two_file_regular_function_access(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);

extern int      test_simple_link_with_callback(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_simple_embedded_header_link(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);

extern int      test_execute_after_simple_compile_and_link(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_execute_after_simple_compile_and_link_no_device_info(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_execute_after_simple_compile_and_link_with_defines(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_execute_after_simple_compile_and_link_with_callbacks(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_execute_after_simple_library_with_link(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_execute_after_two_file_link(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_execute_after_embedded_header_link(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_execute_after_included_header_link(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_execute_after_serialize_reload_object(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_execute_after_serialize_reload_library(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);

extern int      test_simple_library_only(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_simple_library_with_callback(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_simple_library_with_link(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_two_file_link(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_multi_file_libraries(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_multiple_libraries(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_multiple_files(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_multiple_files_multiple_libraries(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_multiple_embedded_headers(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);

extern int      test_program_binary_type(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);
extern int      test_compile_and_link_status_options_log(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);

extern int      test_pragma_unroll(cl_device_id deviceID, cl_context context, cl_command_queue queue, int num_elements);