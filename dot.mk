# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit from Z00T device
$(call inherit-product, device/asus/Z00T/device.mk)

# Inherit some common LineageOS stuff.
$(call inherit-product, vendor/dot/config/common_full_phone.mk)

PRODUCT_NAME := dot_Z00T
PRODUCT_BRAND := asus
PRODUCT_MANUFACTURER := asus
PRODUCT_DEVICE := Z00T
PRODUCT_MODEL := Z00T

PRODUCT_GMS_CLIENTID_BASE := android-asus

DOT_OFFICIAL := true
