{
  "targets": [
    {
      "target_name": "bt_hid_keyboard",
      "conditions": [
        ["OS==\"mac\"", 
          {
            "sources": [
              "darwin/hid.c",
              "main.cc",
            ],
            "include_dirs": [
              "darwin",
              "<!@(node -p \"require('node-addon-api').include\")",
            ],
          },
        ],
        ["OS==\"win\"", {
           "sources": [
            "src/hid.c",
            "main.cc" 
            ],
            "libraries": [
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
        }],
      ],
      "defines": [
        "NAPI_DISABLE_CPP_EXCEPTIONS"
      ]
    }
  ]
}
