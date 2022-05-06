/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ElectronicRegistrationIdentificationVehicleDataModule"
 * 	found in "asn1/ISO24534-3_ElectronicRegistrationIdentificationVehicleDataModule-patched.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_EuVehicleCategoryL_H_
#define	_EuVehicleCategoryL_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum EuVehicleCategoryL {
	EuVehicleCategoryL_l1	= 0,
	EuVehicleCategoryL_l2	= 1,
	EuVehicleCategoryL_l3	= 2,
	EuVehicleCategoryL_l4	= 3,
	EuVehicleCategoryL_l5	= 4,
	EuVehicleCategoryL_l6	= 5,
	EuVehicleCategoryL_l7	= 6
} e_EuVehicleCategoryL;

/* EuVehicleCategoryL */
typedef long	 EuVehicleCategoryL_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_EuVehicleCategoryL_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_EuVehicleCategoryL;
extern const asn_INTEGER_specifics_t asn_SPC_EuVehicleCategoryL_specs_1;
asn_struct_free_f EuVehicleCategoryL_free;
asn_struct_print_f EuVehicleCategoryL_print;
asn_constr_check_f EuVehicleCategoryL_constraint;
ber_type_decoder_f EuVehicleCategoryL_decode_ber;
der_type_encoder_f EuVehicleCategoryL_encode_der;
xer_type_decoder_f EuVehicleCategoryL_decode_xer;
xer_type_encoder_f EuVehicleCategoryL_encode_xer;
oer_type_decoder_f EuVehicleCategoryL_decode_oer;
oer_type_encoder_f EuVehicleCategoryL_encode_oer;
per_type_decoder_f EuVehicleCategoryL_decode_uper;
per_type_encoder_f EuVehicleCategoryL_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _EuVehicleCategoryL_H_ */
#include "asn_internal.h"
