{
    "targets": [
        {
            "target_name": "node-win-pixel",
            "sources": [
                "src/node-win-pixel.cpp",
                "src/pixel.cpp"
            ],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")"
            ],
            "defines": ["NAPI_DISABLE_CPP_EXCEPTIONS"],
        }
    ]
}
