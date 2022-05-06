/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "asn1/TS102894-2v131-CDD.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "ReferencePosition.h"

asn_TYPE_member_t asn_MBR_ReferencePosition_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ReferencePosition, latitude),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Latitude,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"latitude"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ReferencePosition, longitude),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Longitude,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"longitude"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ReferencePosition, positionConfidenceEllipse),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PosConfidenceEllipse,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"positionConfidenceEllipse"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ReferencePosition, altitude),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Altitude,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"altitude"
		},
};
static const ber_tlv_tag_t asn_DEF_ReferencePosition_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ReferencePosition_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* latitude */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* longitude */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* positionConfidenceEllipse */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* altitude */
};
asn_SEQUENCE_specifics_t asn_SPC_ReferencePosition_specs_1 = {
	sizeof(struct ReferencePosition),
	offsetof(struct ReferencePosition, _asn_ctx),
	asn_MAP_ReferencePosition_tag2el_1,
	4,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_ReferencePosition = {
	"ReferencePosition",
	"ReferencePosition",
	&asn_OP_SEQUENCE,
	asn_DEF_ReferencePosition_tags_1,
	sizeof(asn_DEF_ReferencePosition_tags_1)
		/sizeof(asn_DEF_ReferencePosition_tags_1[0]), /* 1 */
	asn_DEF_ReferencePosition_tags_1,	/* Same as above */
	sizeof(asn_DEF_ReferencePosition_tags_1)
		/sizeof(asn_DEF_ReferencePosition_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_ReferencePosition_1,
	4,	/* Elements count */
	&asn_SPC_ReferencePosition_specs_1	/* Additional specs */
};

