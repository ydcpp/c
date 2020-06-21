#ifndef v1_container_state_waiting_TEST
#define v1_container_state_waiting_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_container_state_waiting_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_container_state_waiting.h"
v1_container_state_waiting_t* instantiate_v1_container_state_waiting(int include_optional);



v1_container_state_waiting_t* instantiate_v1_container_state_waiting(int include_optional) {
  v1_container_state_waiting_t* v1_container_state_waiting = NULL;
  if (include_optional) {
    v1_container_state_waiting = v1_container_state_waiting_create(
      "0",
      "0"
    );
  } else {
    v1_container_state_waiting = v1_container_state_waiting_create(
      "0",
      "0"
    );
  }

  return v1_container_state_waiting;
}


#ifdef v1_container_state_waiting_MAIN

void test_v1_container_state_waiting(int include_optional) {
    v1_container_state_waiting_t* v1_container_state_waiting_1 = instantiate_v1_container_state_waiting(include_optional);

	cJSON* jsonv1_container_state_waiting_1 = v1_container_state_waiting_convertToJSON(v1_container_state_waiting_1);
	printf("v1_container_state_waiting :\n%s\n", cJSON_Print(jsonv1_container_state_waiting_1));
	v1_container_state_waiting_t* v1_container_state_waiting_2 = v1_container_state_waiting_parseFromJSON(jsonv1_container_state_waiting_1);
	cJSON* jsonv1_container_state_waiting_2 = v1_container_state_waiting_convertToJSON(v1_container_state_waiting_2);
	printf("repeating v1_container_state_waiting:\n%s\n", cJSON_Print(jsonv1_container_state_waiting_2));
}

int main() {
  test_v1_container_state_waiting(1);
  test_v1_container_state_waiting(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_container_state_waiting_MAIN
#endif // v1_container_state_waiting_TEST
