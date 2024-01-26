#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_user_subject.h"



v1_user_subject_t *v1_user_subject_create(
    char *name
    ) {
    v1_user_subject_t *v1_user_subject_local_var = malloc(sizeof(v1_user_subject_t));
    if (!v1_user_subject_local_var) {
        return NULL;
    }
    v1_user_subject_local_var->name = name;

    return v1_user_subject_local_var;
}


void v1_user_subject_free(v1_user_subject_t *v1_user_subject) {
    if(NULL == v1_user_subject){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_user_subject->name) {
        free(v1_user_subject->name);
        v1_user_subject->name = NULL;
    }
    free(v1_user_subject);
}

cJSON *v1_user_subject_convertToJSON(v1_user_subject_t *v1_user_subject) {
    cJSON *item = cJSON_CreateObject();

    // v1_user_subject->name
    if (!v1_user_subject->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_user_subject->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_user_subject_t *v1_user_subject_parseFromJSON(cJSON *v1_user_subjectJSON){

    v1_user_subject_t *v1_user_subject_local_var = NULL;

    // v1_user_subject->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_user_subjectJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1_user_subject_local_var = v1_user_subject_create (
        strdup(name->valuestring)
        );

    return v1_user_subject_local_var;
end:
    return NULL;

}
