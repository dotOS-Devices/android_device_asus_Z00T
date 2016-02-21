/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm.h"

void init_msm_properties(unsigned long msm_id , unsigned long msm_ver, char *board_type)
{
    char platform[PROP_VALUE_MAX];
    char PRJ_ID[PROP_VALUE_MAX];
    int rc;

    UNUSED(msm_id);
    UNUSED(msm_ver);
    UNUSED(board_type);

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    FILE *fp = fopen("/proc/cmdline" , "r");
    fgets(PRJ_ID, sizeof(PRJ_ID), fp);
    pclose(fp);

    if (strstr(PRJ_ID, "PRJ_ID=3")) {
        property_set("ro.build.product", "Z00T");
        property_set("ro.product.model", "ASUS_Z00UDH");
        property_set("ro.product.device", "ASUS_Z00U");
        property_set("ro.product.carrier", "US-ASUS_Z00U-WW_Z00U");
        property_set("ro.build.description", "Z00T-user 5.0.2 LRX22G WW_user_1.17.40.1106_20160202 release-keys");
        property_set("ro.build.fingerprint", "asus/WW_Z00U/ASUS_Z00U_2:5.0.2/LRX22G/WW_user_1.17.40.1106_20160202:user/release-keys");
    } else {
        property_set("ro.build.product", "Z00T");
        property_set("ro.product.model", "ASUS_Z00TD");
        property_set("ro.product.device", "ASUS_Z00T");
        property_set("ro.product.carrier", "US-ASUS_Z00T-WW_Z00T");
        property_set("ro.build.description", "Z00T-user 5.0.2 LRX22G WW_user_1.17.40.1106_20160202 release-keys");
        property_set("ro.build.fingerprint", "asus/WW_Z00T/ASUS_Z00T:5.0.2/LRX22G/WW_user_1.17.40.1106_20160202:user/release-keys");
    }
}