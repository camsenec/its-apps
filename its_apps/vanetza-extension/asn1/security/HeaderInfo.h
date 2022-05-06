/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IEEE1609dot2"
 * 	found in "asn1/IEEE1609dot2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_HeaderInfo_H_
#define	_HeaderInfo_H_


#include "asn_application.h"

/* Including external dependencies */
#include "Psid.h"
#include "Time64.h"
#include "HashedId3.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ThreeDLocation;
struct MissingCrlIdentifier;
struct EncryptionKey;
struct SequenceOfHashedId3;
struct Certificate;

/* HeaderInfo */
typedef struct HeaderInfo {
	Psid_t	 psid;
	Time64_t	*generationTime	/* OPTIONAL */;
	Time64_t	*expiryTime	/* OPTIONAL */;
	struct ThreeDLocation	*generationLocation	/* OPTIONAL */;
	HashedId3_t	*p2pcdLearningRequest	/* OPTIONAL */;
	struct MissingCrlIdentifier	*missingCrlIdentifier	/* OPTIONAL */;
	struct EncryptionKey	*encryptionKey	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	struct SequenceOfHashedId3	*inlineP2pcdRequest	/* OPTIONAL */;
	struct Certificate	*requestedCertificate	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} HeaderInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_HeaderInfo;
extern asn_SEQUENCE_specifics_t asn_SPC_HeaderInfo_specs_1;
extern asn_TYPE_member_t asn_MBR_HeaderInfo_1[9];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ThreeDLocation.h"
#include "MissingCrlIdentifier.h"
#include "EncryptionKey.h"
#include "SequenceOfHashedId3.h"
#include "Certificate.h"

#endif	/* _HeaderInfo_H_ */
#include "asn_internal.h"