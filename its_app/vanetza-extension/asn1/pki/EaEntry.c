/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EtsiTs102941TrustLists"
 * 	found in "asn1/TS102941v131-TrustLists.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "EaEntry.h"

asn_TYPE_member_t asn_MBR_EaEntry_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct EaEntry, eaCertificate),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_EtsiTs103097Certificate,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"eaCertificate"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct EaEntry, aaAccessPoint),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Url,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"aaAccessPoint"
		},
	{ ATF_POINTER, 1, offsetof(struct EaEntry, itsAccessPoint),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Url,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"itsAccessPoint"
		},
};
static const int asn_MAP_EaEntry_oms_1[] = { 2 };
static const ber_tlv_tag_t asn_DEF_EaEntry_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_EaEntry_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* eaCertificate */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* aaAccessPoint */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* itsAccessPoint */
};
asn_SEQUENCE_specifics_t asn_SPC_EaEntry_specs_1 = {
	sizeof(struct EaEntry),
	offsetof(struct EaEntry, _asn_ctx),
	asn_MAP_EaEntry_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_EaEntry_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_EaEntry = {
	"EaEntry",
	"EaEntry",
	&asn_OP_SEQUENCE,
	asn_DEF_EaEntry_tags_1,
	sizeof(asn_DEF_EaEntry_tags_1)
		/sizeof(asn_DEF_EaEntry_tags_1[0]), /* 1 */
	asn_DEF_EaEntry_tags_1,	/* Same as above */
	sizeof(asn_DEF_EaEntry_tags_1)
		/sizeof(asn_DEF_EaEntry_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_EaEntry_1,
	3,	/* Elements count */
	&asn_SPC_EaEntry_specs_1	/* Additional specs */
};

