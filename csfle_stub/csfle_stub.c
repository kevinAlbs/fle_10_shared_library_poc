#include "csfle_macros.h"
#include <stdint.h>

#include "csfle_stub.h"

struct mongo_csfle_v1_status {};

mongo_csfle_v1_status* mongo_csfle_v1_status_create(void) {
   return 0;
}

void mongo_csfle_v1_status_destroy(mongo_csfle_v1_status* status) {
}

int
mongo_csfle_v1_status_get_error(const mongo_csfle_v1_status* status) {
   return 0;
}

const char*
mongo_csfle_v1_status_get_explanation(const mongo_csfle_v1_status* status) {
   return "";
}

int
mongo_csfle_v1_status_get_code(const mongo_csfle_v1_status* status) {
   return 0;
}

struct mongo_csfle_v1_lib {};

mongo_csfle_v1_lib*
mongo_csfle_v1_create(mongo_csfle_v1_status* status) {
   return 0;
}


int mongo_csfle_v1_destroy(mongo_csfle_v1_lib* lib, mongo_csfle_v1_status* status) {
   return 0;
}


uint64_t mongo_csfle_v1_get_version(void) {
   return 0x000000000000ABCD;
}

const char* mongo_csfle_v1_get_version_str(void) {
   return "mongo_csfle_v1-stub";
}

struct mongo_csfle_v1_query_analyzer;

mongo_csfle_v1_query_analyzer* mongo_csfle_v1_query_analyzer_create(
    mongo_csfle_v1_lib* lib, mongo_csfle_v1_status* status) {
       return 0;
}

void
mongo_csfle_v1_query_analyzer_destroy(mongo_csfle_v1_query_analyzer* analyzer) {}

uint8_t*
mongo_csfle_v1_analyze_query(mongo_csfle_v1_query_analyzer* analyzer,
                              const uint8_t* documentBSON,
                              const char* ns_str,
                              uint32_t ns_len,
                              uint32_t *bson_len,
                              mongo_csfle_v1_status* status) {
   return 0;
}

void mongo_csfle_v1_bson_free(uint8_t* bson) {}
