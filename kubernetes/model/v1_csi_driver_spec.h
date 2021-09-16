/*
 * v1_csi_driver_spec.h
 *
 * CSIDriverSpec is the specification of a CSIDriver.
 */

#ifndef _v1_csi_driver_spec_H_
#define _v1_csi_driver_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_csi_driver_spec_t v1_csi_driver_spec_t;

#include "storage_v1_token_request.h"



typedef struct v1_csi_driver_spec_t {
    int attach_required; //boolean
    char *fs_group_policy; // string
    int pod_info_on_mount; //boolean
    int requires_republish; //boolean
    int storage_capacity; //boolean
    list_t *token_requests; //nonprimitive container
    list_t *volume_lifecycle_modes; //primitive container

} v1_csi_driver_spec_t;

v1_csi_driver_spec_t *v1_csi_driver_spec_create(
    int attach_required,
    char *fs_group_policy,
    int pod_info_on_mount,
    int requires_republish,
    int storage_capacity,
    list_t *token_requests,
    list_t *volume_lifecycle_modes
);

void v1_csi_driver_spec_free(v1_csi_driver_spec_t *v1_csi_driver_spec);

v1_csi_driver_spec_t *v1_csi_driver_spec_parseFromJSON(cJSON *v1_csi_driver_specJSON);

cJSON *v1_csi_driver_spec_convertToJSON(v1_csi_driver_spec_t *v1_csi_driver_spec);

#endif /* _v1_csi_driver_spec_H_ */

