{
  "targets": [
    {
      "target_name": "bt_hid_keyboard",
      "sources": [
        "src/hid.c",
        "main.cc" 
        ],
      "libraries": [
        "lib/*",
        "-ldbghelp.lib",
        "-lWS2_32.lib",
        "-ladvapi32.lib",
        "-luser32.lib",
        "-lIPHLPAPI.lib",
        "-lPSAPI.lib",
        "-lUSERENV.lib",
        "-lCRYPT32.lib",
        "-lbcrypt.lib",
        "-lkernel32.lib",
        "-lWINMM.lib",
        "-lSetupapi.lib"
      ],
      "include_dirs": [
        "include",
        "<!@(node -p \"require('node-addon-api').include\")",
        "-L<$(HOMEPATH)AppData\\Local\\node-gyp\\Cache\\12.13.0\\include\\node",
      ],
      "defines": [
        "NAPI_DISABLE_CPP_EXCEPTIONS"
      ]
    }
  ]
}
