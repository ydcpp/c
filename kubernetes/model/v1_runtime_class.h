/*
 * v1_runtime_class.h
 *
 * RuntimeClass defines a class of container runtime supported in the cluster. The RuntimeClass is used to determine which container runtime is used to run all containers in a pod. RuntimeClasses are manually defined by a user or cluster provisioner, and referenced in the PodSpec. The Kubelet is responsible for resolving the RuntimeClassName reference before running the pod.  For more details, see https://kubernetes.io/docs/concepts/containers/runtime-class/
 */

#ifndef _v1_runtime_class_H_
#define _v1_runtime_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_runtime_class_t v1_runtime_class_t;

#include "v1_object_meta.h"
#include "v1_overhead.h"
#include "v1_scheduling.h"



typedef struct v1_runtime_class_t {
    char *api_version; // string
    char *handler; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_overhead_t *overhead; //model
    struct v1_scheduling_t *scheduling; //model

} v1_runtime_class_t;

v1_runtime_class_t *v1_runtime_class_create(
    char *api_version,
    char *handler,
    char *kind,
    v1_object_meta_t *metadata,
    v1_overhead_t *overhead,
    v1_scheduling_t *scheduling
);

void v1_runtime_class_free(v1_runtime_class_t *v1_runtime_class);

v1_runtime_class_t *v1_runtime_class_parseFromJSON(cJSON *v1_runtime_classJSON);

cJSON *v1_runtime_class_convertToJSON(v1_runtime_class_t *v1_runtime_class);

#endif /* _v1_runtime_class_H_ */

