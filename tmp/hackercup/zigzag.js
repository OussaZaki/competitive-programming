function zigzag(a) {
    var max = 1;
    var zigzag_i = 1;
    var first = true;
    var zig, old;

    for (var i = 0; i < a.length - 1; i += 1) {
        var diff = a[i] - a[i + 1];
        if (diff === 0) {
            if (zigzag_i > max) {
                max = zigzag_i;
            }
            zigzag_i = 1;
            first = true;
            
            continue;
        }

        zig = old * diff;
        old = diff;

        if(!first && zig > 0) {
            if (zigzag_i > max) {
                max = zigzag_i;
            }
            zigzag_i = 1;
        }

        zigzag_i += 1;
        first = false;
    }
    
    if (zigzag_i > max) {
        max = zigzag_i;
    }
    return max;
}
