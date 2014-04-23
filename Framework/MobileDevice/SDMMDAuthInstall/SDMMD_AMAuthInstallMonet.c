//
//  SDMMD_AMAuthInstallMonet.c
//  SDMMobileDevice-Framework
//
//  Created by Sam Marshall on 4/22/14.
//
//

#ifndef SDMMobileDevice_Framework_SDMMD_AMAuthInstallMonet_c
#define SDMMobileDevice_Framework_SDMMD_AMAuthInstallMonet_c

#include "SDMMD_AMAuthInstallMonet.h"

#if 0

function _AMAuthInstallMonetStitchSbl1(CFStringRef rdi, rsi, CFDictionaryRef rdx, rcx, r8) {
	return _AMAuthInstallMonetStitchEBootLoader(CFStringRef rdi, rsi, CFDictionaryRef rdx, rcx, _kAMAuthInstallTagBbSbl1Stitch);
}

function _AMAuthInstallMonetStitchENandprog(CFStringRef rdi, rsi, CFDictionaryRef rdx, rcx, r8) {
	return _AMAuthInstallMonetStitchEBootLoader(CFStringRef rdi, rsi, CFDictionaryRef rdx, rcx, _kAMAuthInstallTagBbENandprogStitch);
}

function _AMAuthInstallMonetStitchRestoreDbl(CFStringRef rdi, rsi, CFDictionaryRef rdx, rcx, r8) {
	return _AMAuthInstallMonetStitchEBootLoader(CFStringRef rdi, rsi, CFDictionaryRef rdx, rcx, _kAMAuthInstallTagBbRestoreDblStitch);
}

function _AMAuthInstallMonetStitchRestoreDbl(CFStringRef rdi, rsi, CFDictionaryRef rdx, rcx, r8) {
	return _AMAuthInstallMonetStitchEBootLoader(CFStringRef rdi, rsi, CFDictionaryRef rdx, rcx, _kAMAuthInstallTagBbRestoreDblStitch);
}

function _AMAuthInstallMonetStitchEDbl(CFStringRef rdi, rsi, CFDictionaryRef rdx, rcx, r8) {
	return _AMAuthInstallMonetStitchEBootLoader(CFStringRef rdi, rsi, CFDictionaryRef rdx, rcx, _kAMAuthInstallTagBbEDblStitch);
}

function _AMAuthInstallMonetMeasureENandprog(CFStringRef rdi, rsi, CFDictionaryRef rdx, rcx, r8) {
	return _AMAuthInstallMonetMeasureEBootLoader(CFStringRef rdi, rsi, CFDictionaryRef rdx, _kAMAuthInstallTagBbEnandprogVersion, _kAMAuthInstallTagBbEnandprogPartialDigest);
}

function _AMAuthInstallMonetMeasureRestoreDbl(CFStringRef rdi, rsi, CFDictionaryRef rdx, rcx, r8) {
    rax = _AMAuthInstallMonetMeasureEBootLoader(CFStringRef rdi, rsi, CFDictionaryRef rdx, _kAMAuthInstallTagBbRestoreDblVersion /*"com.apple.EmbeddedSoftwareRestore.Baseband.ChipId"*/, _kAMAuthInstallTagBbRestoreDblPartialDigest);
    return rax;
}

function _AMAuthInstallMonetStitchDbl(CFStringRef rdi, rsi, CFDictionaryRef rdx, rcx, r8) {
	return _AMAuthInstallMonetStitchEBootLoader(CFStringRef rdi, rsi, CFDictionaryRef rdx, _kAMAuthInstallTagBbEDblVersion, _kAMAuthInstallTagBbEDblPartialDigest);
}

function _AMAuthInstallMonetStitchEBootLoader(CFStringRef rdi, rsi, CFDictionaryRef rdx, rcx, r8) {
    r15 = r8;
    var_16 = rcx;
    r13 = rsi;
    r12 = rdi;
    CFStringRef var_32 = CFStringCreateWithFormat(kCFAllocatorDefault, NULL, CFSTR("%@-Original"), r12);
    CFStringRef var_24 = CFStringCreateWithFormat(kCFAllocatorDefault, NULL, CFSTR("%@-Personalized"), r12);
    CFTypeRef rax = CFDictionaryGetValue(rdx, _kAMAuthInstallTagBbFirmware);
    if (rax != 0x0) {
		// loc_453cd:
		r14 = CFDictionaryGetValue(rax, r15);
		if (r14 != 0x0) {
			// loc_453e4:
			if (CFDataGetLength(r14) >= CFDataGetLength(rsi)) {
				// loc_45502:
				_AMAuthInstallLog(0x3, "_AMAuthInstallMonetStitchFirstStage", "stitch data is larger than file");
				LODWORD(r12) = 0x1;
				// loc_45522;
			}
			else {
				// loc_45400;
			    CFDataRef r15 = CFDataCreateMutableCopy(kCFAllocatorDefault, NULL, rsi);
			    var_8 = r12;
			    LODWORD(r12) = 0x2;
			    var_0 = r13;
			    if (r15 == 0x0) {
					// loc_45522;
				}
				UInt8 *data_ptr = CFDataGetMutableBytePtr(r15);
			    memcpy(&(data_ptr[CFDataGetLength(r15) - CFDataGetLength(r14)]), CFDataGetBytePtr(r14), CFDataGetLength(r14));
			    *var_16 = CFRetain(r15);
			    _SafeRelease(r15);
			    r14 = var_32;
			    _AMAuthInstallDebugWriteObject(var_8, var_0, r14, 0x1);
			    rbx = var_24;
			    _AMAuthInstallDebugWriteObject(var_8, *var_16, rbx, 0x1);
			    LODWORD(r12) = 0x0;
			    // loc_45531;
			}
		}
	}
	
	// loc_454f3;
    _AMAuthInstallLog();
    LODWORD(r12) = 0x8;
	
	// loc_45522:
    _SafeRelease(0x0);
    r14 = var_32;
    rbx = var_24;
	
	// loc_45531:
    _SafeRelease(r14);
    _SafeRelease(rbx);
    LODWORD(rax) = LODWORD(r12);
    return rax;
}

function _AMAuthInstallMonetMeasureElf(rdi, CFDataRef rsi, rdx, rcx, r8) {
    var_16 = r8;
    var_32 = rcx;
    var_24 = rdx;
    rbx = rsi;
    r14 = rdi;
    if (!(CFDataGetLength(rbx) <= 0x33)) {
		// loc_459a9;
	    r15 = r14;
	    rax = CFDataGetBytePtr(rbx);
	    if (*(int32_t *)rax != 0x464c457f) {
			// loc_45b37;
		}
	    r14 = rbx;
	    LODWORD(rcx) = *(int16_t *)(rax + 0x2c) & 0xffff;
	    if (LODWORD(rcx) == 0x0) {
			// loc_45b45;
		}
	    rdx = *(int32_t *)(rax + 0x1c) + rax;
	    LODWORD(rbx) = 0x0;
	    LODWORD(rax) = 0x0;
	    do {
			LODWORD(rdi) = *(int32_t *)(rdx + 0xc);
			if (LODWORD(rdi) > LODWORD(rax)) {
				if (LODWORD(LODWORD(*(int32_t *)(rdx + 0x18)) & LODWORD(0x7000000)) != 0x5000000) {
					LODWORD(rax) = LODWORD(rdi);
				}
				if (CPU_FLAGS & E) {
					rbx = rdx;
				}
			}
			rdx = rdx + 0x20;
			LODWORD(rcx) = LODWORD(rcx) - 0x1;
	    } while (CPU_FLAGS & NE);
	    if (rbx == 0x0) {
			// loc_45b45;
		}
	    var_8 = r15;
	    r13 = CFDataCreateMutable(kCFAllocatorDefault, 0x14);
	    LODWORD(r15) = 0x2;
	    LODWORD(r12) = 0x0;
	    if (r13 == 0x0) {
		 	// loc_45b82:
			LODWORD(r13) = 0x0;
			// loc_45b5d;
	    }
		else {
			// loc_45a3b;
		    CFDataSetLength(r13, 0x14);
		    CC_SHA1_Init(&var_40);
		    CC_SHA1_Update(&var_40, *(int32_t *)(rbx + 0x4) + CFDataGetBytePtr(r14), *(int32_t *)(rbx + 0x10));
		    CC_SHA1_Final(CFDataGetMutableBytePtr(r13), &var_40);
		    r12 = CFDataCreateMutable(CFGetAllocator(var_8), 0x14);
		    if (r12 == 0x0) {
				// loc_45b5a;
			}
		    CFDataSetLength(r12, 0x14);
		    CC_SHA1_Init(&var_40);
		    CC_SHA1_Update(&var_40, CFDataGetBytePtr(r14), LODWORD(CFDataGetLength(r14)));
		    CC_SHA1_Final(CFDataGetMutableBytePtr(r12), &var_40);
		    CFDictionarySetValue(var_24, var_16, r12);
		    CFDictionarySetValue(var_24, var_32, r13);
		    LODWORD(r15) = 0x0;
		    //  loc_45b5d;
		}
	}
	
	//loc_45b37:
	
	//loc_45b45:
    _AMAuthInstallLog(0x3);
    LODWORD(r15) = 0xa;
    LODWORD(r13) = 0x0;
	
	// loc_45b5a:
    LODWORD(r12) = 0x0;
	
	// loc_45b5d:
    _SafeRelease(r12);
    _SafeRelease(r13);
    LODWORD(rax) = LODWORD(r15);
    return rax;
}

function _AMAuthInstallMonetMeasureAmss(rdi, CFDataRef rsi, rdx, rcx, r8) {
    rax = _AMAuthInstallMonetMeasureElf(rdi, CFDataRef rsi, rdx,_kAMAuthInstallTagBbAmssHashSectionDigest, _kAMAuthInstallTagBbAmssDownloadDigest);
    return rax;
}


#endif

#endif