[ ## this file was manually modified by jt
    {
     'functor' : {
         'description' : ['The function returns the high part of the entry',
                          'shifted right as an integer of the same size as',
                          'the input.'],
         'return' : ['always returns an integer value'],
          'module' : 'boost',
         'arity' : '1',
         'call_types' : [],
         'ret_arity' : '0',
         'rturn' : {
             'default' : 'typename boost::dispatch::meta::downgrade<ir_t>::type',
            },
         'type_defs' : ['typedef typename boost::dispatch::meta::as_integer<T,unsigned>::type ir_t;',
                        'typedef typename boost::dispatch::meta::downgrade<ir_t>::type dtype;',
                        'typedef typename boost::simd::meta::scalar_of<ir_t>::type scal;'],
         'types' : ['real_', 'int64_', 'int32_', 'int16_'],
         'simd_types' : ['real_', 'sintgt_8_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 18/02/2011',
             'included' : ['#include <boost/dispatch/meta/downgrade.hpp>'],
             'no_ulp' : 'True',
             'notes' : [],
             'stamp' : 'modified by jt the 18/02/2011',
            },
         'ranges' : {
             'default' : [['boost::simd::Valmin<T>()/2', 'boost::simd::Valmax<T>()/2']],
             'sintgt_8_' :  [['boost::simd::Valmin<T>()/2', 'boost::simd::Valmax<T>()/2']],
            },
         'specific_values' : {
             'default' : {
                 'boost::simd::One<T>()' : {'result' : 'boost::simd::Zero<dtype>()','ulp_thresh' : '0.5',},
                 'boost::simd::Zero<T>()' : {'result' : 'boost::simd::Zero<dtype>()','ulp_thresh' : '0.5',},
                },
             'real_' : {
                 'boost::simd::Nan<T>()' : {'result' : 'boost::simd::Mone<dtype>()','ulp_thresh' : '0.5',},
                 'boost::simd::Zero<T>()' : {'result' : 'boost::simd::Zero<dtype>()','ulp_thresh' : '0.5',},
                },
            },
         'verif_test' : {
             'property_call' : {
                },
             'property_value' : {
                },
             'simd' : {
                },
             'ulp_thresh' : {
                },
            },
        },
    },
]
