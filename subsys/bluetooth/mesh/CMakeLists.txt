#
# Copyright (c) 2018 Nordic Semiconductor
#
# SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
#

zephyr_sources_ifdef(CONFIG_BT_MESH_NORDIC_MODELS model_utils.c)

zephyr_sources_ifdef(CONFIG_BT_MESH_ONOFF_SRV gen_onoff_srv.c)
zephyr_sources_ifdef(CONFIG_BT_MESH_ONOFF_CLI gen_onoff_cli.c)

zephyr_sources_ifdef(CONFIG_BT_MESH_LVL_SRV gen_lvl_srv.c)
zephyr_sources_ifdef(CONFIG_BT_MESH_LVL_CLI gen_lvl_cli.c)

zephyr_sources_ifdef(CONFIG_BT_MESH_DTT_SRV gen_dtt_srv.c)
zephyr_sources_ifdef(CONFIG_BT_MESH_DTT_CLI gen_dtt_cli.c)

zephyr_sources_ifdef(CONFIG_BT_MESH_PONOFF_SRV gen_ponoff_srv.c)
zephyr_sources_ifdef(CONFIG_BT_MESH_PONOFF_CLI gen_ponoff_cli.c)

zephyr_sources_ifdef(CONFIG_BT_MESH_PLVL_SRV gen_plvl_srv.c)
zephyr_sources_ifdef(CONFIG_BT_MESH_PLVL_CLI gen_plvl_cli.c)

zephyr_sources_ifdef(CONFIG_BT_MESH_BATTERY_SRV gen_battery_srv.c)
zephyr_sources_ifdef(CONFIG_BT_MESH_BATTERY_CLI gen_battery_cli.c)

zephyr_sources_ifdef(CONFIG_BT_MESH_LOC_SRV gen_loc_srv.c)
zephyr_sources_ifdef(CONFIG_BT_MESH_LOC_CLI gen_loc_cli.c)

zephyr_sources_ifdef(CONFIG_BT_MESH_PROP_SRV gen_prop_srv.c)
zephyr_sources_ifdef(CONFIG_BT_MESH_PROP_CLI gen_prop_cli.c)
