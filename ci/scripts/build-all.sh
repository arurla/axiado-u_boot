#!/usr/bin/env bash
set -e 

OPENBMC_DIR="../openbmc" 
if [ -d "${OPENBMC_DIR}" ]; then
    cd "${OPENBMC_DIR}"
else
    echo "ERROR: openbmc directory in path ${OPENBMC_DIR} not found."
    exit 1
fi

if [ "${BRANCH_NAME}" ]; then
    # Update release branch name on flowmeter recipie file with value of BRANCH_NAME environment variable
    # Can be used for building flowmeter from a feature or bugfix branch
    sed -i "s+^SRCBRANCH .*+SRCBRANCH ?= \"${BRANCH_NAME}\"+g" meta-axiado/recipes-bsp/u-boot/u-boot-axiado_2022.01.bb
    cat meta-axiado/recipes-bsp/u-boot/u-boot-axiado_2022.01.bb
    echo "Executing on Branch : ${BRANCH_NAME}"
fi

ci/scripts/build-all.sh u-boot