# SPDX-License-Identifier: LGPL-2.1-or-later

# CloudSync gui init module
# (c) 2001 Juergen Riegel LGPL


class CloudSyncWorkbench(Workbench):
    "CloudSync workbench object"

    MenuText = "CloudSync"
    ToolTip = "CloudSync workbench"

    def Initialize(self):
        # load the module
        import CloudSyncGui

    def GetClassName(self):
        return "CloudSyncGui::Workbench"


Gui.addWorkbench(CloudSyncWorkbench())
