#ifndef v1_replication_controller_spec_TEST
#define v1_replication_controller_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_replication_controller_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_replication_controller_spec.h"
v1_replication_controller_spec_t* instantiate_v1_replication_controller_spec(int include_optional);

#include "test_v1_pod_template_spec.c"


v1_replication_controller_spec_t* instantiate_v1_replication_controller_spec(int include_optional) {
  v1_replication_controller_spec_t* v1_replication_controller_spec = NULL;
  if (include_optional) {
    v1_replication_controller_spec = v1_replication_controller_spec_create(
      56,
      56,
      list_createList(),
       // false, not to have infinite recursion
      instantiate_v1_pod_template_spec(0)
    );
  } else {
    v1_replication_controller_spec = v1_replication_controller_spec_create(
      56,
      56,
      list_createList(),
      NULL
    );
  }

  return v1_replication_controller_spec;
}


#ifdef v1_replication_controller_spec_MAIN

void test_v1_replication_controller_spec(int include_optional) {
    v1_replication_controller_spec_t* v1_replication_controller_spec_1 = instantiate_v1_replication_controller_spec(include_optional);

	cJSON* jsonv1_replication_controller_spec_1 = v1_replication_controller_spec_convertToJSON(v1_replication_controller_spec_1);
	printf("v1_replication_controller_spec :\n%s\n", cJSON_Print(jsonv1_replication_controller_spec_1));
	v1_replication_controller_spec_t* v1_replication_controller_spec_2 = v1_replication_controller_spec_parseFromJSON(jsonv1_replication_controller_spec_1);
	cJSON* jsonv1_replication_controller_spec_2 = v1_replication_controller_spec_convertToJSON(v1_replication_controller_spec_2);
	printf("repeating v1_replication_controller_spec:\n%s\n", cJSON_Print(jsonv1_replication_controller_spec_2));
}

int main() {
  test_v1_replication_controller_spec(1);
  test_v1_replication_controller_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_replication_controller_spec_MAIN
#endif // v1_replication_controller_spec_TEST
