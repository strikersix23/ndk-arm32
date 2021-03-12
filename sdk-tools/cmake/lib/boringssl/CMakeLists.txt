cmake_minimum_required(VERSION 3.14.2)

project(boringssl)

set(BORINGSSL ${AOSP}/external/boringssl)

set(LIBCRYPTO_SRC_FILES
    ${BORINGSSL}/linux-aarch64/crypto/fipsmodule/aesv8-armx64.S
    ${BORINGSSL}/linux-aarch64/crypto/fipsmodule/armv8-mont.S
    ${BORINGSSL}/linux-aarch64/crypto/fipsmodule/ghash-neon-armv8.S
    ${BORINGSSL}/linux-aarch64/crypto/fipsmodule/ghashv8-armx64.S
    ${BORINGSSL}/linux-aarch64/crypto/fipsmodule/sha1-armv8.S
    ${BORINGSSL}/linux-aarch64/crypto/fipsmodule/sha256-armv8.S
    ${BORINGSSL}/linux-aarch64/crypto/fipsmodule/sha512-armv8.S
    ${BORINGSSL}/linux-aarch64/crypto/fipsmodule/vpaes-armv8.S
    ${BORINGSSL}/src/crypto/fipsmodule/bcm.c
    ${BORINGSSL}/err_data.c
    ${BORINGSSL}/src/crypto/asn1/a_bitstr.c
    ${BORINGSSL}/src/crypto/asn1/a_bool.c
    ${BORINGSSL}/src/crypto/asn1/a_d2i_fp.c
    ${BORINGSSL}/src/crypto/asn1/a_dup.c
    ${BORINGSSL}/src/crypto/asn1/a_enum.c
    ${BORINGSSL}/src/crypto/asn1/a_gentm.c
    ${BORINGSSL}/src/crypto/asn1/a_i2d_fp.c
    ${BORINGSSL}/src/crypto/asn1/a_int.c
    ${BORINGSSL}/src/crypto/asn1/a_mbstr.c
    ${BORINGSSL}/src/crypto/asn1/a_object.c
    ${BORINGSSL}/src/crypto/asn1/a_octet.c
    ${BORINGSSL}/src/crypto/asn1/a_print.c
    ${BORINGSSL}/src/crypto/asn1/a_strnid.c
    ${BORINGSSL}/src/crypto/asn1/a_time.c
    ${BORINGSSL}/src/crypto/asn1/a_type.c
    ${BORINGSSL}/src/crypto/asn1/a_utctm.c
    ${BORINGSSL}/src/crypto/asn1/a_utf8.c
    ${BORINGSSL}/src/crypto/asn1/asn1_lib.c
    ${BORINGSSL}/src/crypto/asn1/asn1_par.c
    ${BORINGSSL}/src/crypto/asn1/asn_pack.c
    ${BORINGSSL}/src/crypto/asn1/f_enum.c
    ${BORINGSSL}/src/crypto/asn1/f_int.c
    ${BORINGSSL}/src/crypto/asn1/f_string.c
    ${BORINGSSL}/src/crypto/asn1/tasn_dec.c
    ${BORINGSSL}/src/crypto/asn1/tasn_enc.c
    ${BORINGSSL}/src/crypto/asn1/tasn_fre.c
    ${BORINGSSL}/src/crypto/asn1/tasn_new.c
    ${BORINGSSL}/src/crypto/asn1/tasn_typ.c
    ${BORINGSSL}/src/crypto/asn1/tasn_utl.c
    ${BORINGSSL}/src/crypto/asn1/time_support.c
    ${BORINGSSL}/src/crypto/base64/base64.c
    ${BORINGSSL}/src/crypto/bio/bio.c
    ${BORINGSSL}/src/crypto/bio/bio_mem.c
    ${BORINGSSL}/src/crypto/bio/connect.c
    ${BORINGSSL}/src/crypto/bio/fd.c
    ${BORINGSSL}/src/crypto/bio/file.c
    ${BORINGSSL}/src/crypto/bio/hexdump.c
    ${BORINGSSL}/src/crypto/bio/pair.c
    ${BORINGSSL}/src/crypto/bio/printf.c
    ${BORINGSSL}/src/crypto/bio/socket.c
    ${BORINGSSL}/src/crypto/bio/socket_helper.c
    ${BORINGSSL}/src/crypto/blake2/blake2.c
    ${BORINGSSL}/src/crypto/bn_extra/bn_asn1.c
    ${BORINGSSL}/src/crypto/bn_extra/convert.c
    ${BORINGSSL}/src/crypto/buf/buf.c
    ${BORINGSSL}/src/crypto/bytestring/asn1_compat.c
    ${BORINGSSL}/src/crypto/bytestring/ber.c
    ${BORINGSSL}/src/crypto/bytestring/cbb.c
    ${BORINGSSL}/src/crypto/bytestring/cbs.c
    ${BORINGSSL}/src/crypto/bytestring/unicode.c
    ${BORINGSSL}/src/crypto/chacha/chacha.c
    ${BORINGSSL}/src/crypto/cipher_extra/cipher_extra.c
    ${BORINGSSL}/src/crypto/cipher_extra/derive_key.c
    ${BORINGSSL}/src/crypto/cipher_extra/e_aesccm.c
    ${BORINGSSL}/src/crypto/cipher_extra/e_aesctrhmac.c
    ${BORINGSSL}/src/crypto/cipher_extra/e_aesgcmsiv.c
    ${BORINGSSL}/src/crypto/cipher_extra/e_chacha20poly1305.c
    ${BORINGSSL}/src/crypto/cipher_extra/e_null.c
    ${BORINGSSL}/src/crypto/cipher_extra/e_rc2.c
    ${BORINGSSL}/src/crypto/cipher_extra/e_rc4.c
    ${BORINGSSL}/src/crypto/cipher_extra/e_tls.c
    ${BORINGSSL}/src/crypto/cipher_extra/tls_cbc.c
    ${BORINGSSL}/src/crypto/cmac/cmac.c
    ${BORINGSSL}/src/crypto/conf/conf.c
    ${BORINGSSL}/src/crypto/cpu-aarch64-fuchsia.c
    ${BORINGSSL}/src/crypto/cpu-aarch64-linux.c
    ${BORINGSSL}/src/crypto/cpu-aarch64-win.c
    ${BORINGSSL}/src/crypto/cpu-arm-linux.c
    ${BORINGSSL}/src/crypto/cpu-arm.c
    ${BORINGSSL}/src/crypto/cpu-intel.c
    ${BORINGSSL}/src/crypto/cpu-ppc64le.c
    ${BORINGSSL}/src/crypto/crypto.c
    ${BORINGSSL}/src/crypto/curve25519/curve25519.c
    ${BORINGSSL}/src/crypto/curve25519/spake25519.c
    ${BORINGSSL}/src/crypto/dh_extra/dh_asn1.c
    ${BORINGSSL}/src/crypto/dh_extra/params.c
    ${BORINGSSL}/src/crypto/digest_extra/digest_extra.c
    ${BORINGSSL}/src/crypto/dsa/dsa.c
    ${BORINGSSL}/src/crypto/dsa/dsa_asn1.c
    ${BORINGSSL}/src/crypto/ec_extra/ec_asn1.c
    ${BORINGSSL}/src/crypto/ec_extra/ec_derive.c
    ${BORINGSSL}/src/crypto/ec_extra/hash_to_curve.c
    ${BORINGSSL}/src/crypto/ecdh_extra/ecdh_extra.c
    ${BORINGSSL}/src/crypto/ecdsa_extra/ecdsa_asn1.c
    ${BORINGSSL}/src/crypto/engine/engine.c
    ${BORINGSSL}/src/crypto/err/err.c
    ${BORINGSSL}/src/crypto/evp/digestsign.c
    ${BORINGSSL}/src/crypto/evp/evp.c
    ${BORINGSSL}/src/crypto/evp/evp_asn1.c
    ${BORINGSSL}/src/crypto/evp/evp_ctx.c
    ${BORINGSSL}/src/crypto/evp/p_dsa_asn1.c
    ${BORINGSSL}/src/crypto/evp/p_ec.c
    ${BORINGSSL}/src/crypto/evp/p_ec_asn1.c
    ${BORINGSSL}/src/crypto/evp/p_ed25519.c
    ${BORINGSSL}/src/crypto/evp/p_ed25519_asn1.c
    ${BORINGSSL}/src/crypto/evp/p_rsa.c
    ${BORINGSSL}/src/crypto/evp/p_rsa_asn1.c
    ${BORINGSSL}/src/crypto/evp/p_x25519.c
    ${BORINGSSL}/src/crypto/evp/p_x25519_asn1.c
    ${BORINGSSL}/src/crypto/evp/pbkdf.c
    ${BORINGSSL}/src/crypto/evp/print.c
    ${BORINGSSL}/src/crypto/evp/scrypt.c
    ${BORINGSSL}/src/crypto/evp/sign.c
    ${BORINGSSL}/src/crypto/ex_data.c
    ${BORINGSSL}/src/crypto/fipsmodule/bcm.c
    ${BORINGSSL}/src/crypto/fipsmodule/fips_shared_support.c
    ${BORINGSSL}/src/crypto/fipsmodule/is_fips.c
    ${BORINGSSL}/src/crypto/hkdf/hkdf.c
    ${BORINGSSL}/src/crypto/hpke/hpke.c
    ${BORINGSSL}/src/crypto/hrss/hrss.c
    ${BORINGSSL}/src/crypto/lhash/lhash.c
    ${BORINGSSL}/src/crypto/mem.c
    ${BORINGSSL}/src/crypto/obj/obj.c
    ${BORINGSSL}/src/crypto/obj/obj_xref.c
    ${BORINGSSL}/src/crypto/pem/pem_all.c
    ${BORINGSSL}/src/crypto/pem/pem_info.c
    ${BORINGSSL}/src/crypto/pem/pem_lib.c
    ${BORINGSSL}/src/crypto/pem/pem_oth.c
    ${BORINGSSL}/src/crypto/pem/pem_pk8.c
    ${BORINGSSL}/src/crypto/pem/pem_pkey.c
    ${BORINGSSL}/src/crypto/pem/pem_x509.c
    ${BORINGSSL}/src/crypto/pem/pem_xaux.c
    ${BORINGSSL}/src/crypto/pkcs7/pkcs7.c
    ${BORINGSSL}/src/crypto/pkcs7/pkcs7_x509.c
    ${BORINGSSL}/src/crypto/pkcs8/p5_pbev2.c
    ${BORINGSSL}/src/crypto/pkcs8/pkcs8.c
    ${BORINGSSL}/src/crypto/pkcs8/pkcs8_x509.c
    ${BORINGSSL}/src/crypto/poly1305/poly1305.c
    ${BORINGSSL}/src/crypto/poly1305/poly1305_arm.c
    ${BORINGSSL}/src/crypto/poly1305/poly1305_vec.c
    ${BORINGSSL}/src/crypto/pool/pool.c
    ${BORINGSSL}/src/crypto/rand_extra/deterministic.c
    ${BORINGSSL}/src/crypto/rand_extra/forkunsafe.c
    ${BORINGSSL}/src/crypto/rand_extra/fuchsia.c
    ${BORINGSSL}/src/crypto/rand_extra/passive.c
    ${BORINGSSL}/src/crypto/rand_extra/rand_extra.c
    ${BORINGSSL}/src/crypto/rand_extra/windows.c
    ${BORINGSSL}/src/crypto/rc4/rc4.c
    ${BORINGSSL}/src/crypto/refcount_c11.c
    ${BORINGSSL}/src/crypto/refcount_lock.c
    ${BORINGSSL}/src/crypto/rsa_extra/rsa_asn1.c
    ${BORINGSSL}/src/crypto/rsa_extra/rsa_print.c
    ${BORINGSSL}/src/crypto/siphash/siphash.c
    ${BORINGSSL}/src/crypto/stack/stack.c
    ${BORINGSSL}/src/crypto/thread.c
    ${BORINGSSL}/src/crypto/thread_none.c
    ${BORINGSSL}/src/crypto/thread_pthread.c
    ${BORINGSSL}/src/crypto/thread_win.c
    ${BORINGSSL}/src/crypto/trust_token/pmbtoken.c
    ${BORINGSSL}/src/crypto/trust_token/trust_token.c
    ${BORINGSSL}/src/crypto/trust_token/voprf.c
    ${BORINGSSL}/src/crypto/x509/a_digest.c
    ${BORINGSSL}/src/crypto/x509/a_sign.c
    ${BORINGSSL}/src/crypto/x509/a_strex.c
    ${BORINGSSL}/src/crypto/x509/a_verify.c
    ${BORINGSSL}/src/crypto/x509/algorithm.c
    ${BORINGSSL}/src/crypto/x509/asn1_gen.c
    ${BORINGSSL}/src/crypto/x509/by_dir.c
    ${BORINGSSL}/src/crypto/x509/by_file.c
    ${BORINGSSL}/src/crypto/x509/i2d_pr.c
    ${BORINGSSL}/src/crypto/x509/rsa_pss.c
    ${BORINGSSL}/src/crypto/x509/t_crl.c
    ${BORINGSSL}/src/crypto/x509/t_req.c
    ${BORINGSSL}/src/crypto/x509/t_x509.c
    ${BORINGSSL}/src/crypto/x509/t_x509a.c
    ${BORINGSSL}/src/crypto/x509/x509.c
    ${BORINGSSL}/src/crypto/x509/x509_att.c
    ${BORINGSSL}/src/crypto/x509/x509_cmp.c
    ${BORINGSSL}/src/crypto/x509/x509_d2.c
    ${BORINGSSL}/src/crypto/x509/x509_def.c
    ${BORINGSSL}/src/crypto/x509/x509_ext.c
    ${BORINGSSL}/src/crypto/x509/x509_lu.c
    ${BORINGSSL}/src/crypto/x509/x509_obj.c
    ${BORINGSSL}/src/crypto/x509/x509_r2x.c
    ${BORINGSSL}/src/crypto/x509/x509_req.c
    ${BORINGSSL}/src/crypto/x509/x509_set.c
    ${BORINGSSL}/src/crypto/x509/x509_trs.c
    ${BORINGSSL}/src/crypto/x509/x509_txt.c
    ${BORINGSSL}/src/crypto/x509/x509_v3.c
    ${BORINGSSL}/src/crypto/x509/x509_vfy.c
    ${BORINGSSL}/src/crypto/x509/x509_vpm.c
    ${BORINGSSL}/src/crypto/x509/x509cset.c
    ${BORINGSSL}/src/crypto/x509/x509name.c
    ${BORINGSSL}/src/crypto/x509/x509rset.c
    ${BORINGSSL}/src/crypto/x509/x509spki.c
    ${BORINGSSL}/src/crypto/x509/x_algor.c
    ${BORINGSSL}/src/crypto/x509/x_all.c
    ${BORINGSSL}/src/crypto/x509/x_attrib.c
    ${BORINGSSL}/src/crypto/x509/x_crl.c
    ${BORINGSSL}/src/crypto/x509/x_exten.c
    ${BORINGSSL}/src/crypto/x509/x_info.c
    ${BORINGSSL}/src/crypto/x509/x_name.c
    ${BORINGSSL}/src/crypto/x509/x_pkey.c
    ${BORINGSSL}/src/crypto/x509/x_pubkey.c
    ${BORINGSSL}/src/crypto/x509/x_req.c
    ${BORINGSSL}/src/crypto/x509/x_sig.c
    ${BORINGSSL}/src/crypto/x509/x_spki.c
    ${BORINGSSL}/src/crypto/x509/x_val.c
    ${BORINGSSL}/src/crypto/x509/x_x509.c
    ${BORINGSSL}/src/crypto/x509/x_x509a.c
    ${BORINGSSL}/src/crypto/x509v3/pcy_cache.c
    ${BORINGSSL}/src/crypto/x509v3/pcy_data.c
    ${BORINGSSL}/src/crypto/x509v3/pcy_lib.c
    ${BORINGSSL}/src/crypto/x509v3/pcy_map.c
    ${BORINGSSL}/src/crypto/x509v3/pcy_node.c
    ${BORINGSSL}/src/crypto/x509v3/pcy_tree.c
    ${BORINGSSL}/src/crypto/x509v3/v3_akey.c
    ${BORINGSSL}/src/crypto/x509v3/v3_akeya.c
    ${BORINGSSL}/src/crypto/x509v3/v3_alt.c
    ${BORINGSSL}/src/crypto/x509v3/v3_bcons.c
    ${BORINGSSL}/src/crypto/x509v3/v3_bitst.c
    ${BORINGSSL}/src/crypto/x509v3/v3_conf.c
    ${BORINGSSL}/src/crypto/x509v3/v3_cpols.c
    ${BORINGSSL}/src/crypto/x509v3/v3_crld.c
    ${BORINGSSL}/src/crypto/x509v3/v3_enum.c
    ${BORINGSSL}/src/crypto/x509v3/v3_extku.c
    ${BORINGSSL}/src/crypto/x509v3/v3_genn.c
    ${BORINGSSL}/src/crypto/x509v3/v3_ia5.c
    ${BORINGSSL}/src/crypto/x509v3/v3_info.c
    ${BORINGSSL}/src/crypto/x509v3/v3_int.c
    ${BORINGSSL}/src/crypto/x509v3/v3_lib.c
    ${BORINGSSL}/src/crypto/x509v3/v3_ncons.c
    ${BORINGSSL}/src/crypto/x509v3/v3_ocsp.c
    ${BORINGSSL}/src/crypto/x509v3/v3_pci.c
    ${BORINGSSL}/src/crypto/x509v3/v3_pcia.c
    ${BORINGSSL}/src/crypto/x509v3/v3_pcons.c
    ${BORINGSSL}/src/crypto/x509v3/v3_pmaps.c
    ${BORINGSSL}/src/crypto/x509v3/v3_prn.c
    ${BORINGSSL}/src/crypto/x509v3/v3_purp.c
    ${BORINGSSL}/src/crypto/x509v3/v3_skey.c
    ${BORINGSSL}/src/crypto/x509v3/v3_utl.c
    )

set(LIBSSL_SRC_FILES
    ${BORINGSSL}/src/ssl/bio_ssl.cc
    ${BORINGSSL}/src/ssl/d1_both.cc
    ${BORINGSSL}/src/ssl/d1_lib.cc
    ${BORINGSSL}/src/ssl/d1_pkt.cc
    ${BORINGSSL}/src/ssl/d1_srtp.cc
    ${BORINGSSL}/src/ssl/dtls_method.cc
    ${BORINGSSL}/src/ssl/dtls_record.cc
    ${BORINGSSL}/src/ssl/handoff.cc
    ${BORINGSSL}/src/ssl/handshake.cc
    ${BORINGSSL}/src/ssl/handshake_client.cc
    ${BORINGSSL}/src/ssl/handshake_server.cc
    ${BORINGSSL}/src/ssl/s3_both.cc
    ${BORINGSSL}/src/ssl/s3_lib.cc
    ${BORINGSSL}/src/ssl/s3_pkt.cc
    ${BORINGSSL}/src/ssl/ssl_aead_ctx.cc
    ${BORINGSSL}/src/ssl/ssl_asn1.cc
    ${BORINGSSL}/src/ssl/ssl_buffer.cc
    ${BORINGSSL}/src/ssl/ssl_cert.cc
    ${BORINGSSL}/src/ssl/ssl_cipher.cc
    ${BORINGSSL}/src/ssl/ssl_file.cc
    ${BORINGSSL}/src/ssl/ssl_key_share.cc
    ${BORINGSSL}/src/ssl/ssl_lib.cc
    ${BORINGSSL}/src/ssl/ssl_privkey.cc
    ${BORINGSSL}/src/ssl/ssl_session.cc
    ${BORINGSSL}/src/ssl/ssl_stat.cc
    ${BORINGSSL}/src/ssl/ssl_transcript.cc
    ${BORINGSSL}/src/ssl/ssl_versions.cc
    ${BORINGSSL}/src/ssl/ssl_x509.cc
    ${BORINGSSL}/src/ssl/t1_enc.cc
    ${BORINGSSL}/src/ssl/t1_lib.cc
    ${BORINGSSL}/src/ssl/tls13_both.cc
    ${BORINGSSL}/src/ssl/tls13_client.cc
    ${BORINGSSL}/src/ssl/tls13_enc.cc
    ${BORINGSSL}/src/ssl/tls13_server.cc
    ${BORINGSSL}/src/ssl/tls_method.cc
    ${BORINGSSL}/src/ssl/tls_record.cc
    )

set(DEFAULT_FLAGS " \
    -fvisibility=hidden \
    -DBORINGSSL_SHARED_LIBRARY \
    -DBORINGSSL_ANDROID_SYSTEM \
    -DOPENSSL_SMALL \
    -D_XOPEN_SOURCE=700 \
    -Werror \
    -Wno-unused-parameter \
    -DBORINGSSL_FIPS \
    -fPIC \
    -fno-data-sections \
    -fno-function-sections \
    ")

set(CMAKE_C_FLAGS " \
    ${GLOBAL_C_FLAGS} \
    ${DEFAULT_FLAGS} \
    ")

set(CMAKE_CXX_FLAGS " \
    ${GLOBAL_CXX_FLAGS} \
    ${DEFAULT_FLAGS} \
    -DBORINGSSL_IMPLEMENTATION \
    ")

include_directories(
    ${BORINGSSL}/src/include
    ${BORINGSSL}/src/crypto
    )

add_library(crypto STATIC ${LIBCRYPTO_SRC_FILES})
target_link_libraries(crypto)

add_library(ssl STATIC ${LIBSSL_SRC_FILES})
target_link_libraries(ssl)


