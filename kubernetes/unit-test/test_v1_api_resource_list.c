#ifndef v1_api_resource_list_TEST
#define v1_api_resource_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_api_resource_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_api_resource_list.h"
v1_api_resource_list_t* instantiate_v1_api_resource_list(int include_optional);



v1_api_resource_list_t* instantiate_v1_api_resource_list(int include_optional) {
  v1_api_resource_list_t* v1_api_resource_list = NULL;
  if (include_optional) {
    v1_api_resource_list = v1_api_resource_list_create(
      "0",
      "0",
      "0",
      list_createList()
    );
  } else {
    v1_api_resource_list = v1_api_resource_list_create(
      "0",
      "0",
      "0",
      list_createList()
    );
  }

  return v1_api_resource_list;
}


#ifdef v1_api_resource_list_MAIN

void test_v1_api_resource_list(int include_optional) {
    v1_api_resource_list_t* v1_api_resource_list_1 = instantiate_v1_api_resource_list(include_optional);

	cJSON* jsonv1_api_resource_list_1 = v1_api_resource_list_convertToJSON(v1_api_resource_list_1);
	printf("v1_api_resource_list :\n%s\n", cJSON_Print(jsonv1_api_resource_list_1));
	v1_api_resource_list_t* v1_api_resource_list_2 = v1_api_resource_list_parseFromJSON(jsonv1_api_resource_list_1);
	cJSON* jsonv1_api_resource_list_2 = v1_api_resource_list_convertToJSON(v1_api_resource_list_2);
	printf("repeating v1_api_resource_list:\n%s\n", cJSON_Print(jsonv1_api_resource_list_2));
}

int main() {
  test_v1_api_resource_list(1);
  test_v1_api_resource_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_api_resource_list_MAIN
#endif // v1_api_resource_list_TEST
