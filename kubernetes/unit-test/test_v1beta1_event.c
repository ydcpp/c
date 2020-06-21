#ifndef v1beta1_event_TEST
#define v1beta1_event_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_event_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_event.h"
v1beta1_event_t* instantiate_v1beta1_event(int include_optional);

#include "test_v1_event_source.c"
#include "test_v1_object_meta.c"
#include "test_v1_object_reference.c"
#include "test_v1_object_reference.c"
#include "test_v1beta1_event_series.c"


v1beta1_event_t* instantiate_v1beta1_event(int include_optional) {
  v1beta1_event_t* v1beta1_event = NULL;
  if (include_optional) {
    v1beta1_event = v1beta1_event_create(
      "0",
      "0",
      56,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
       // false, not to have infinite recursion
      instantiate_v1_event_source(0),
      "2013-10-20T19:20:30+01:00",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_reference(0),
       // false, not to have infinite recursion
      instantiate_v1_object_reference(0),
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1beta1_event_series(0),
      "0"
    );
  } else {
    v1beta1_event = v1beta1_event_create(
      "0",
      "0",
      56,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      NULL,
      "2013-10-20T19:20:30+01:00",
      "0",
      NULL,
      "0",
      "0",
      NULL,
      NULL,
      "0",
      "0",
      NULL,
      "0"
    );
  }

  return v1beta1_event;
}


#ifdef v1beta1_event_MAIN

void test_v1beta1_event(int include_optional) {
    v1beta1_event_t* v1beta1_event_1 = instantiate_v1beta1_event(include_optional);

	cJSON* jsonv1beta1_event_1 = v1beta1_event_convertToJSON(v1beta1_event_1);
	printf("v1beta1_event :\n%s\n", cJSON_Print(jsonv1beta1_event_1));
	v1beta1_event_t* v1beta1_event_2 = v1beta1_event_parseFromJSON(jsonv1beta1_event_1);
	cJSON* jsonv1beta1_event_2 = v1beta1_event_convertToJSON(v1beta1_event_2);
	printf("repeating v1beta1_event:\n%s\n", cJSON_Print(jsonv1beta1_event_2));
}

int main() {
  test_v1beta1_event(1);
  test_v1beta1_event(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_event_MAIN
#endif // v1beta1_event_TEST
