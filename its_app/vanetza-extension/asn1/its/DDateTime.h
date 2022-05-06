/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "asn1/ISO-TS-19091-addgrp-C-2018.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_DDateTime_H_
#define	_DDateTime_H_


#include "asn_application.h"

/* Including external dependencies */
#include "DYear.h"
#include "DMonth.h"
#include "DDay.h"
#include "DHour.h"
#include "DMinute.h"
#include "DSecond.h"
#include "DOffset.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* DDateTime */
typedef struct DDateTime {
	DYear_t	*year	/* OPTIONAL */;
	DMonth_t	*month	/* OPTIONAL */;
	DDay_t	*day	/* OPTIONAL */;
	DHour_t	*hour	/* OPTIONAL */;
	DMinute_t	*minute	/* OPTIONAL */;
	DSecond_t	*second	/* OPTIONAL */;
	DOffset_t	*offset	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DDateTime_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DDateTime;
extern asn_SEQUENCE_specifics_t asn_SPC_DDateTime_specs_1;
extern asn_TYPE_member_t asn_MBR_DDateTime_1[7];

#ifdef __cplusplus
}
#endif

#endif	/* _DDateTime_H_ */
#include "asn_internal.h"
