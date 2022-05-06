/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "asn1/ISO-TS-19091-addgrp-C-2018.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_SignalRequestPackage_H_
#define	_SignalRequestPackage_H_


#include "asn_application.h"

/* Including external dependencies */
#include "SignalRequest.h"
#include "MinuteOfTheYear.h"
#include "DSecond.h"
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RegionalExtension;

/* SignalRequestPackage */
typedef struct SignalRequestPackage {
	SignalRequest_t	 request;
	MinuteOfTheYear_t	*minute	/* OPTIONAL */;
	DSecond_t	*second	/* OPTIONAL */;
	DSecond_t	*duration	/* OPTIONAL */;
	struct SignalRequestPackage__regional {
		A_SEQUENCE_OF(struct RegionalExtension) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *regional;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SignalRequestPackage_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SignalRequestPackage;
extern asn_SEQUENCE_specifics_t asn_SPC_SignalRequestPackage_specs_1;
extern asn_TYPE_member_t asn_MBR_SignalRequestPackage_1[5];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "RegionalExtension.h"

#endif	/* _SignalRequestPackage_H_ */
#include "asn_internal.h"
