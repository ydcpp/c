#ifndef extensions_v1beta1_ingress_backend_TEST
#define extensions_v1beta1_ingress_backend_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extensions_v1beta1_ingress_backend_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extensions_v1beta1_ingress_backend.h"
extensions_v1beta1_ingress_backend_t* instantiate_extensions_v1beta1_ingress_backend(int include_optional);



extensions_v1beta1_ingress_backend_t* instantiate_extensions_v1beta1_ingress_backend(int include_optional) {
  extensions_v1beta1_ingress_backend_t* extensions_v1beta1_ingress_backend = NULL;
  if (include_optional) {
    extensions_v1beta1_ingress_backend = extensions_v1beta1_ingress_backend_create(
      "0",
      0
    );
  } else {
    extensions_v1beta1_ingress_backend = extensions_v1beta1_ingress_backend_create(
      "0",
      0
    );
  }

  return extensions_v1beta1_ingress_backend;
}


#ifdef extensions_v1beta1_ingress_backend_MAIN

void test_extensions_v1beta1_ingress_backend(int include_optional) {
    extensions_v1beta1_ingress_backend_t* extensions_v1beta1_ingress_backend_1 = instantiate_extensions_v1beta1_ingress_backend(include_optional);

	cJSON* jsonextensions_v1beta1_ingress_backend_1 = extensions_v1beta1_ingress_backend_convertToJSON(extensions_v1beta1_ingress_backend_1);
	printf("extensions_v1beta1_ingress_backend :\n%s\n", cJSON_Print(jsonextensions_v1beta1_ingress_backend_1));
	extensions_v1beta1_ingress_backend_t* extensions_v1beta1_ingress_backend_2 = extensions_v1beta1_ingress_backend_parseFromJSON(jsonextensions_v1beta1_ingress_backend_1);
	cJSON* jsonextensions_v1beta1_ingress_backend_2 = extensions_v1beta1_ingress_backend_convertToJSON(extensions_v1beta1_ingress_backend_2);
	printf("repeating extensions_v1beta1_ingress_backend:\n%s\n", cJSON_Print(jsonextensions_v1beta1_ingress_backend_2));
}

int main() {
  test_extensions_v1beta1_ingress_backend(1);
  test_extensions_v1beta1_ingress_backend(0);

  printf("Hello world \n");
  return 0;
}

#endif // extensions_v1beta1_ingress_backend_MAIN
#endif // extensions_v1beta1_ingress_backend_TEST
